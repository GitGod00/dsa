#include <stdio.h>
#include <stdlib.h>

// Structure for priority queue node
struct PriorityQueueNode {
    int data;
    int priority;
    struct PriorityQueueNode* next;
};

// Structure for priority queue
struct PriorityQueue {
    struct PriorityQueueNode* front;
};

// Function to initialize the priority queue
void initializePriorityQueue(struct PriorityQueue* pq) {
    pq->front = NULL;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return (pq->front == NULL);
}

// Function to create a new priority queue node
struct PriorityQueueNode* createNode(int data, int priority) {
    struct PriorityQueueNode* newNode = (struct PriorityQueueNode*)malloc(sizeof(struct PriorityQueueNode));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue an element into the priority queue based on priority
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct PriorityQueueNode* newNode = createNode(data, priority);

    // If the priority queue is empty or the new node has higher priority
    if (isEmpty(pq) || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct PriorityQueueNode* temp = pq->front;

        // Find the position to insert the new node
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to dequeue an element from the priority queue
void dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct PriorityQueueNode* temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
}

// Function to display the priority queue
void displayPriorityQueue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    struct PriorityQueueNode* temp = pq->front;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    initializePriorityQueue(&pq);

    // Enqueue elements into the priority queue
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);

    // Display priority queue
    displayPriorityQueue(&pq);

    // Dequeue an element
    dequeue(&pq);

    // Display priority queue after dequeue
    displayPriorityQueue(&pq);

    return 0;
}
