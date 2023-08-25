#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List * newList = (List *)malloc(sizeof(List));
    assert(newList != NULL);
    newList->head = NULL;
    newList->tail = NULL;
    newList->current = NULL;
    return newList;
}

void * firstList(List * list) {
  if(!list || !list->head) return NULL;
  list->current = list->head;
  return list->head->data;
}

void * nextList(List * list) {
  if(!list || !list->current || !list->current->next) return NULL;
  list->current = list->current->next;
  return list->current->data;
  return NULL;
}

void * lastList(List * list) {
  if(!list || !list->tail) return NULL;
  list->current = list->tail;
  return list->tail->data;
}

void * prevList(List * list) {
  if(!list || !list->current || !list->current->prev)return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  Node *newNode = createNode(data);
  if(!list || !newNode) return;
  if(list->head) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    } else {
        list->head = newNode;
        list->tail = newNode;
    }
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  if(!list) return;
    if(!list->current) {
        pushFront(list, data);
        return;
    }

    Node *newNode = createNode(data);
    if(!newNode) return;

    newNode->next = list->current->next;
    newNode->prev = list->current;
    if(list->current->next) {
        list->current->next->prev = newNode;
    } else {
        list->tail = newNode;
    }
    list->current->next = newNode;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if(!list || !list->current) return NULL;
  Nde *toDelete = list->current;
  void* data = toDlete->data
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}