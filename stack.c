#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure for stack
struct Stack {
    int top;
    int array[MAX_SIZE];
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    stack->array[++stack->top] = value;
}

// Function to pop an element from the stack
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }

    stack->top--;
}

// Function to get the top element of the stack
int top(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // or any suitable value indicating an error
    }

    return stack->array[stack->top];
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display top element
    printf("Top element: %d\n", top(&stack));

    // Pop an element
    pop(&stack);

    // Display top element after pop
    printf("Top element after pop: %d\n", top(&stack));

    return 0;
}
