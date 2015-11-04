#include<stdio.h>
#include<stdlib.h>

#define default 0
#ifndef LIST_H
#define LIST_H 1

struct node;
typedef struct node * ptrNode;
typedef struct node * position;
typedef int ElementType;
typedef struct node* List;

position CreateList(void);
void DeleteNode(List l,ElementType e);
position CreateNode(ElementType e);
void Insert(List l,ElementType e,position);
void Append(List l,ElementType e);
void Connect(List l1,List l2);
void DeleteList(List l);
void MakeEmpty(List l);
void reverse(List l);

int isEmpty(List l);
int isLast(List l);
position next(position p);
position previous(List l,position p);
position findElement(List l,ElementType e);
position Last(List l);
void printList(List l);

#endif
