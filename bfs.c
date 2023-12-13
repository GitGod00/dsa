#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for a queue
struct Queue {
    int front, rear;
    int capacity;
    struct TreeNode** array;
};

// Function to create a new tree node with given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to enqueue a tree node into the queue
void enqueue(struct Queue* queue, struct TreeNode* node) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->array[queue->rear] = node;
}

// Function to dequeue a tree node from the queue
struct TreeNode* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    struct TreeNode* frontNode = queue->array[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;

    return frontNode;
}

// Function to perform breadth-first search (BFS) on a binary tree
void bfsTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue(MAX_SIZE);
    enqueue(queue, root);

    printf("BFS Traversal: ");

    while (!isEmpty(queue)) {
        struct TreeNode* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);

        if (current->right != NULL)
            enqueue(queue, current->right);
    }

    printf("\n");
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // BFS traversal
    bfsTraversal(root);

    return 0;
}

//Graphs
#include <stdio.h>
#include <stdlib.h>
#define S 50   // Size of the stack and queue
#define MAX 10 // Maximum number of nodes in the graph
// Stack structure
typedef struct
{
    int b[S];
    int tos;
} Stack;
// Queue structure
typedef struct
{
    int a[S];
    int front, rear;
} Queue;
// Graph structure
typedef struct
{
    int adj[MAX][MAX];
    int e, v;
} Graph;
// Function to check if the stack is empty
int isEmpty(Stack s)
{
    return s.tos == -1;
}
// Function to dequeue from the queue
int dequeue(Queue *q)
{
    int x = q->a[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return x;
}
// Function to enqueue into the queue
void enqueue(Queue *q, int e)
{
    q->rear++;
    q->a[q->rear] = e;
    if (q->front == -1)
    {
        q->front = 0;
    }
}
// Function to push into the stack
void push(Stack *s, int e)
{
    s->tos++;
    s->b[s->tos] = e;
}
// Function to pop from the stack
int pop(Stack *s)
{
    int x = s->b[s->tos];
    s->tos--;
    return x;
}
// Function to initialize the graph
void initializeGraph(Graph *g)
{
    for (int i = 0; i < g->v; i++)
    {
        for (int j = 0; j < g->v; j++)
        {
            g->adj[i][j] = 0;
        }
    }
}
// Function to add an edge to the graph
void add(Graph *g, int src, int dest)
{
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; // For an undirected graph
}
// Iterative DFS traversal
void dfsIterative(int root, Graph g, int visited[])
{
    Stack s;
    s.tos = -1;
    push(&s, root);
    while (!isEmpty(s))
    {
        int x = pop(&s);
        if (visited[x] != 1)
        {
            visited[x] = 1;
            printf("%d\t", x);
            for (int i = 0; i < g.v; i++)
            {
                if (g.adj[x][i] == 1 && visited[i] != 1)
                {
                    push(&s, i);
                }
            }
        }
    }
}
// BFS traversal using iterative method
void bfsTraversal(int root, Graph g, int visited[])
{
    Queue q;
    q.front = q.rear = -1;
    enqueue(&q, root);
    while (q.front != -1)
    {
        int x = dequeue(&q);
        if (visited[x] != 1)
        {
            visited[x] = 1;
            printf("%d\t", x);
            for (int i = 0; i < g.v; i++)
            {
                if (g.adj[x][i] == 1 && visited[i] != 1)
                {
                    enqueue(&q, i);
                }
            }
        }
    }
}
// Function to print the adjacency matrix
void printAdjMatrix(Graph g)
{
    for (int i = 0; i < g.v; i++)
    {
        for (int j = 0; j < g.v; j++)
        {
            printf("%d ", g.adj[i][j]);
        }
        printf("\n");
    }
}
// Function to reset the visited array
void reset(int visited[])
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
    }
}
int main()
{
    Graph g;
    int visited[MAX] = {0};
    int root, src, dest, c;
    printf("Enter the number of vertices for the directed graph: ");
    scanf("%d", &g.v);
    printf("Enter the number of edges for the directed graph: ");
    scanf("%d", &g.e);
    initializeGraph(&g);
    for (int i = 1; i <= g.e; i++)
    {
        printf("Enter the source node value: ");
        scanf("%d", &src);
        printf("Enter the destination node value: ");
        scanf("%d", &dest);
        add(&g, src, dest);
    }
    printf("Printing the adjacency matrix:\n");
    printAdjMatrix(g);
    do
    {
        printf("\nChoose your operation:\n1. DFS Iteration\n2. BFS Traversal\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        reset(visited);
        switch (c)
        {
        case 1:
            printf("Enter the root: ");
            scanf("%d", &root);
            printf("DFS Iterative\n");
            dfsIterative(root, g, visited);
            break;

        case 2:

            printf("Enter the root\n");
            scanf("%d", &root);
            printf("BFS Iterative\n");
            bfsTraversal(root, g, visited);
            break;
        case 4:
            exit(0);
        }
    } while (1);
    return 0;
}