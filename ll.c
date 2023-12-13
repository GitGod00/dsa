#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *createLinkedList(int numNodes)
{
    struct Node *head = NULL;
    struct Node *current = NULL;

    for (int i = 0; i < numNodes; i++)
    {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node *newNode = createNode(data);

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

struct Node *insertAtIndex(struct Node *head, int index)
{
    int data;
    printf("\n Enter the data");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);
    if (index == 0)
    {
        newNode->next = head;
    }
    else
    {
        struct Node *p = head;

        for (int i = 1; i < index - 1 && p != NULL; i++)
        {
            p = p->next;
        }
        if (p != NULL)
        {
            newNode->next = p->next;
            p->next = newNode;
        }
    }
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

void displayFromValue(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d --> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main()
{
    int numNodes;
    char gg[10];
    int index;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes < 1)
    {
        printf("Number of nodes should be greater than 0\n");
        return 1;
    }

    struct Node *head = createLinkedList(numNodes);

    printf("Linked list before deletion:\n");
    displayFromValue(head);

    printf("\nDo you want to delete the last element? (yes/no): ");
    scanf("%s", gg);

    if (strcmp(gg, "yes") == 0)
    {
        head = deleteLast(head);
        printf("\nLinked list after deletion:\n");
        displayFromValue(head);
    }
    printf("\nIndex at which you want to insert data");
    scanf("%d", &index);

    head = insertAtIndex(head, index);
    printf("\n Linkd List after insertion:\n");
    displayFromValue(head);

    // Free remaining memory
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *createLinkedList(int numNodes)
{
    struct Node *head = NULL;
    struct Node *current = NULL;

    for (int i = 0; i < numNodes; i++)
    {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node *newNode = createNode(data);

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

struct Node *insertAtIndex(struct Node *head, int index)
{
    int data;
    printf("\n Enter the data");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);
    if (index == 0)
    {
        newNode->next = head;
    }
    else
    {
        struct Node *p = head;

        for (int i = 1; i < index - 1 && p != NULL; i++)
        {
            p = p->next;
        }
        if (p != NULL)
        {
            newNode->next = p->next;
            p->next = newNode;
        }
    }
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

void displayFromValue(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d --> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main()
{
    int numNodes;
    char gg[10];
    int index;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes < 1)
    {
        printf("Number of nodes should be greater than 0\n");
        return 1;
    }

    struct Node *head = createLinkedList(numNodes);

    printf("Linked list before deletion:\n");
    displayFromValue(head);

    printf("\nDo you want to delete the last element? (yes/no): ");
    scanf("%s", gg);

    if (strcmp(gg, "yes") == 0)
    {
        head = deleteLast(head);
        printf("\nLinked list after deletion:\n");
        displayFromValue(head);
    }
    printf("\nIndex at which you want to insert data");
    scanf("%d", &index);

    head = insertAtIndex(head, index);
    printf("\n Linkd List after insertion:\n");
    displayFromValue(head);

    // Free remaining memory
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
