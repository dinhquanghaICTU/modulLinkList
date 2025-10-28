#include "modulLinkList.h"
#include <string.h>

void initList(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

void addTail(LinkedList *list, void *data, size_t dataSize) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = malloc(dataSize);
    memcpy(newNode->data, data, dataSize);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    list->size++;
}

void printList(LinkedList *list, void (*printFunc)(void *)) {
    Node *temp = list->head;
    while (temp != NULL) {
        printFunc(temp->data);
        temp = temp->next;
    }
}

void freeList(LinkedList *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        Node *del = temp;
        temp = temp->next;
        free(del->data);
        free(del);
    }
    list->head = NULL;
    list->size = 0;
}




void initQueue(Queue *q) {
    initList(q); 
}

int isEmptyQueue(Queue *q) {
    return (q->head == NULL);
}

void enqueue(Queue *q, void *data, size_t dataSize) {
    addTail(q, data, dataSize); 
}

void *dequeue(Queue *q) {
    if (isEmptyQueue(q)) return NULL;
    Node *temp = q->head;
    void *data = temp->data;
    q->head = temp->next;
    free(temp);
    q->size--;
    return data; 
}

void *peekQueue(Queue *q) {
    if (isEmptyQueue(q)) return NULL;
    return q->head->data;
}

void freeQueue(Queue *q) {
    freeList(q);
}
