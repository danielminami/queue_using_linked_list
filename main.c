/*
Daniel Minami <minamid@sheridancollege.ca>
----------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *front = NULL;
node_t *rear = NULL;


bool isEmpty() {
    return (front == NULL || rear == NULL);
}

node_t* createNode(int newValue) {
    node_t* newNode = (node_t*) malloc( sizeof(node_t) );
    newNode->data = newValue;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int value) {
    node_t *newNode = createNode(value);
    if (newNode == NULL) {
        printf("No memory available");
    } else {
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int dequeue() {
    int value = 0;
    if (isEmpty()) {
        printf("Queue is empty");
    } else {
        value = front->data;
        front = front->next;
        return value;
    }
}

void printQueue() {
    printf("Printing all elements: \n");
    node_t* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    printQueue();
    dequeue();
    printQueue();

    exit(0);
}

