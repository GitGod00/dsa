#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a stack
struct Stack {
    int data;
    struct Stack* next;
};

// Function to check if the stack is empty
int isEmpty(struct Stack* top) {
    return (top == NULL);
}

// Function to push an integer onto the stack
struct Stack* push(struct Stack* top, int value) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Function to pop an integer from the stack
struct Stack* pop(struct Stack* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return NULL;
    }

    struct Stack* temp = top;
    top = top->next;
    free(temp);
    return top;
}

// Function to evaluate a prefix expression
int evaluatePrefixExpression(char prefix[]) {
    struct Stack* stack = NULL;
    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            stack = push(stack, prefix[i] - '0');
        } else {
            int operand1, operand2;

            // Pop two operands from the stack
            if (!isEmpty(stack))
                operand1 = stack->data;
            else {
                printf("Invalid expression.\n");
                exit(1);
            }

            stack = pop(stack);

            if (!isEmpty(stack))
                operand2 = stack->data;
            else {
                printf("Invalid expression.\n");
                exit(1);
            }

            stack = pop(stack);

            // Perform operation and push result onto the stack
            switch (prefix[i]) {
                case '+':
                    stack = push(stack, operand1 + operand2);
                    break;
                case '-':
                    stack = push(stack, operand1 - operand2);
                    break;
                case '*':
                    stack = push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0)
                        stack = push(stack, operand1 / operand2);
                    else {
                        printf("Division by zero is not allowed.\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Invalid expression.\n");
                    exit(1);
            }
        }
    }

    if (!isEmpty(stack)) {
        int result = stack->data;
        stack = pop(stack);
        return result;
    } else {
        printf("Invalid expression.\n");
        exit(1);
    }
}

int main() {
    char prefix[100];

    // Input
    printf("Enter the prefix expression: ");
    scanf("%s", prefix);

    // Evaluate prefix expression
    int result = evaluatePrefixExpression(prefix);

    // Output
    printf("Result: %d\n", result);

    return 0;
}
