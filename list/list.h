#include<stdio.h>
#include<stdlib.h>

#define default 0
#ifndef LIST_H
#define LIST_H 1

struct node;
typedef struct node * ptrNode;
typedef struct node * position;
typedef int element_type;
typedef struct node* LIST;

int is_empty(LIST L);
void make_empty(LIST L);
position create_node(element_type x);
void delete_node(LIST L,position p);
position creat_list();
void delete_list(LIST L);
void insert(position p,element_type x);
position previous(LIST L,position p);

#endif
