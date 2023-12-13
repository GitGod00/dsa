#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure for queue
struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = value;
}

// Function to dequeue an element from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
}

// Function to get the front element of the queue
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1; // or any suitable value indicating an error
    }

    return queue->array[queue->front];
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    // Enqueue elements into the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Display front element
    printf("Front element: %d\n", front(&queue));

    // Dequeue an element
    dequeue(&queue);

    // Display front element after dequeue
    printf("Front element after dequeue: %d\n", front(&queue));

    return 0;
}
