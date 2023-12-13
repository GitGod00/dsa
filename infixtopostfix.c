#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for stack
struct Stack {
    char data;
    struct Stack* next;
};

// Function to check if the stack is empty
int isEmpty(struct Stack* top) {
    return (top == NULL);
}

// Function to push a character onto the stack
struct Stack* push(struct Stack* top, char value) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Function to pop a character from the stack
struct Stack* pop(struct Stack* top) {
    if (isEmpty(top)) {
        return NULL;
    }

    struct Stack* temp = top;
    top = top->next;
    free(temp);
    return top;
}

// Function to get the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack* stack = NULL;
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack = push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->data != '(') {
                postfix[j++] = stack->data;
                stack = pop(stack);
            }
            if (!isEmpty(stack) && stack->data != '(') {
                printf("Invalid expression.\n");
                exit(1);
            } else {
                stack = pop(stack);
            }
        } else {
            while (!isEmpty(stack) && getPrecedence(infix[i]) <= getPrecedence(stack->data)) {
                postfix[j++] = stack->data;
                stack = pop(stack);
            }
            stack = push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = stack->data;
        stack = pop(stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    // Input
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
