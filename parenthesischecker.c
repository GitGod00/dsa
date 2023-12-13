#include <stdio.h>
#include <stdlib.h>

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
        printf("Stack is empty.\n");
        return top;
    }

    struct Stack* temp = top;
    top = top->next;
    free(temp);
    return top;
}

// Function to check if parentheses are balanced
int areParenthesesBalanced(char expression[]) {
    struct Stack* stack = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            stack = push(stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(stack)) {
                return 0; // Unbalanced
            }

            char popped = stack->data;
            stack = pop(stack);

            if ((expression[i] == ')' && popped != '(') ||
                (expression[i] == ']' && popped != '[') ||
                (expression[i] == '}' && popped != '{')) {
                return 0; // Unbalanced
            }
        }
    }

    return isEmpty(stack); // Balanced if the stack is empty
}

int main() {
    char expression[100];

    // Input
    printf("Enter the expression: ");
    scanf("%s", expression);

    // Check if parentheses are balanced
    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are unbalanced.\n");
    }

    return 0;
}
