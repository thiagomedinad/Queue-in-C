#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node{
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} queue;

// Initialize the queue structure
void init_queue(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

// Add a new element to the queue
bool enqueue(queue *q, int value) {

    // Create a memory location to the new element
    node * newnode = malloc(sizeof(node));
    
    // returns false if there's no more space 
    if (newnode == NULL) return false;

    // New node get the value
    newnode->value = value;

    // As the new node is the tail, there's no "next"
    newnode->next = NULL;

    // If there is any element in the queue
    // The next item will be the new node
    if (q->tail != NULL)
    {
        q->tail->next = newnode;
    }

    // The new node, as the newest element in the queue,
    // is now the tail
    q->tail = newnode;

    // If the head is null, there are no elements in the queue
    // so the new node is now the head
    if (q->head == NULL)
    {
        q->head = newnode;
    }

    return true;
}

// Take items from the queue
int dequeue(queue *q) {
    // Check if there's any element in the queue
    if (q->head == NULL) return QUEUE_EMPTY;

    // Create a aux variable to the head of the queue
    node *tmp = q->head;

    // Store the value from the head into the return variable 
    int result = tmp->value;

    // Updates the queue's head
    q->head = q->head->next;

    if (q->head == NULL)
    {
        q->tail == NULL;
    }

    free(tmp);

    return result;
}

int main() {
    queue fila;

    init_queue(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 7);
    enqueue(&fila, 100);

    int t;
    while((t = dequeue(&fila)) != QUEUE_EMPTY) {
        printf("t= %d\n", t);
    }
}   