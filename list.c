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

  Node* n=(Node*)calloc(1,sizeof(Node));

  n->data=data;
  n->next=NULL;
  return n;
}

List * createList() {
  List* l=(List*)calloc(1,sizeof(List));
  l->head=NULL;
  l->tail=NULL;
  l->current=NULL;
  return l;
}

void * firstList(List * list) {

  if(list->head!=NULL){
    list->current=list->head;
    return list->head->data;
  }
  return NULL;
}

void * nextList(List * list) {
  if(list->current->next != NULL){
    list->current=list->current->next;
    return list->current->data;
  }
  return NULL;
}

void * lastList(List * list) {
  if(list->tail!=NULL && list->tail->data!=NULL){
    return list->current=list->tail;
  }
  return NULL;
}

void * prevList(List * list) {
  if(list->current->prev!=NULL && list->current->prev->data!=NULL){

    return list->current=list->current->prev;
  }
  return NULL;
}

void pushFront(List * list, void * data) {
  Node* n=createNode(data);
  if(list->head==NULL){
    list->head=n;
    list->tail=n;
  }else{
    n->next = list->head;
    list->head->prev=n;
  }
  list->head=n;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  
  
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
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}