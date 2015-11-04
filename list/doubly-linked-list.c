#include"doubly-linked-list.h"
#include<stdlib.h>

struct doubly_linked_list_head{
  ptr_node head;
  char* head_info;
};

struct doubly_linked_node{
  object x;
  ptr_node pre;
  ptr_node next;
};

/* 将item作为表头*/
void insert(node item,doubly_list List)
{
  node p = List->head;
  item->next = p;
  if(p != NULL)
    p->pre = item;
  List->head = item;
  item->pre = NULL;
}

doubly_list create_doubly_list(void){
  doubly_list p = (doubly_list) malloc(sizeof(struct doubly_linked_list_head));
  if(p != NULL)
    p->head = (node) NULL;
  char* string = (char *) malloc(20*sizeof(char));
  if(string != NULL){
    string = "this is head";
    p->head_info = string;
  }
  else exit(1);
  return p;
}

void delete(node item,doubly_list List)
{
  if(item->next == NULL){ // item 位于链表尾端
    item->pre->next = item->next;
    item->pre = NULL;
  }
  else if(item->pre == NULL){// item 位于链表首部
    List->head = item->next;
    item->next = NULL;
  }
  else{
    item->pre->next = item->next;
    item->next->pre = item->pre;
    item->next = NULL;
    item->pre = NULL;
  }
  free(item);
}

node search(object key,doubly_list List){
  node p = List->head;
  while(p != NULL && p->x != key)
    p = p->next;
  return p;
}

node create_node(object x){
  node p = (node) malloc(sizeof(struct doubly_linked_node));
  if(p != NULL){
    p->x = x;
    p->next = NULL;
    p->pre = NULL;
  }
  return p;
}
