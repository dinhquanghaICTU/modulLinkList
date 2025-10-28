#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;


void initList(LinkedList *list);


void addTail(LinkedList *list, void *data, size_t dataSize);


void printList(LinkedList *list, void (*printFunc)(void *));


void freeList(LinkedList *list);




typedef LinkedList Queue;

void initQueue(Queue *q);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, void *data, size_t dataSize);
void *dequeue(Queue *q);
void *peekQueue(Queue *q);
void freeQueue(Queue *q);




#endif
