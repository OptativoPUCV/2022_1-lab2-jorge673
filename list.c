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

  Node* n=(Node*)malloc(sizeof(Node));

  n->data=data;
  n->next=NULL;
  return n;
}

List * createList() {
  List* l=(List*)malloc(sizeof(List));
  l->head=NULL;
  l->tail=NULL;
  l->current=NULL;
  return l;
}

void * firstList(List * list) {

  if(list->head != NULL)
  {
    list->current=list->head;
    return list->current->data;
  }
  return NULL;
}

void * nextList(List * list) {
  if(list->current != NULL && list->current->next != NULL)
  {

    list->current=list->current->next;

    if(list->current!=NULL){
      return list->current->data;
    }
  }
  return NULL;
}

void * lastList(List * list) {
  if(list->tail != NULL)
  {

    list->current=list->tail;

    return list->current->data;
  }
  return NULL;
}

void * prevList(List * list) {
  if(list->current != NULL && list->current->prev != NULL)
  {
    list->current=list->current->prev;

    if(list->current!=NULL){
      return list->current->data;
    }
  }
  return NULL;
}

void pushFront(List * list, void * data) {
  Node* n=createNode(data);
  if(list->head==NULL)
  {
    list->head=n;
    list->tail=n;
  }else{
    n->next = list->head;
    list->head->prev=n;
  }
  list->head=n;
}

void pushBack(List * list, void * data) {
  list->current=list->head;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data){
  Node* n=createNode(data);
  if (list->current->next==NULL)
  {
    list->current->next=n;
    n->prev=list->current;
    list->tail=n;
  }else{
    list->current->next=n;
    n->next=list->current->next;
    n->prev=list->current;
  }

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
  if(list->current==NULL) return NULL;
  if(list->current->prev==NULL){
    list->head=list->head->next;
    list->head->prev=NULL;
  }else{
    list->current->next->prev=list->current->prev;
  }
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}