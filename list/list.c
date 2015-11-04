#include "list.h"

struct node{
     ElementType e;
     ptrNode next;
};

position CreateList()
{
     ptrNode header = CreateNode(default);
     header -> next = NULL;
     return header;
}

void DeleteNode(List l,ElementType e)
{
     position p = findElement(l,e);
     position pre = previous(l,p);
     pre -> next = p -> next;
     free(p);
}

position CreateNode(ElementType e)
{
     ptrNode p = malloc(sizeof(struct node));
     if(p == NULL){
          printf("error malloc failed\n");
          exit(0);
     }
     p -> e = e;
     return p;
}

void Insert(List l,ElementType e,position p)
{
     position pre = previous(l,p);
     ptrNode insert_node = CreateNode(e);
     insert_node -> next = p;
     pre -> next = insert_node;
}

void Append(List l,ElementType e)
{
     ptrNode new = CreateNode(e);
     position last = Last(l);
     new -> next = NULL;
     last -> next = new;
}

void Connect(List l1,List l2)
{
     position last = Last(l1);
     last -> next = l2 -> next;
}

void DeleteList(List l)
{
     ptrNode p = l -> next;
     free(l);
     l -> next = NULL;
     while(p != NULL){
          ptrNode tmp = p;
          p = p -> next;
          tmp -> next = NULL;
          free(tmp);
          tmp = NULL;
     }
}

void MakeEmpty(List l)
{
     ptrNode p = l -> next;
     l -> next = NULL;
     while(p != NULL){
          ptrNode tmp = p;
          p = p -> next;
          free(tmp);
     }
}

int isEmpty(List l)
{
     return l -> next == NULL;
}

int isLast(List l)
{
     return l -> next -> next == NULL;
}

position next(position p)
{
     return p -> next;
}

position previous(List l,position p)
{
     ptrNode tmp = l;
     while((tmp -> next) != NULL && (tmp -> next) != p){
          tmp = tmp -> next;
     }
     return tmp;
}

position findElement(List l,ElementType e)
{
     ptrNode p = l -> next;
     while(p != NULL && (p -> e) != e)
     {
          p = p -> next;
     }
     return p;
}

position Last(List l)
{
     ptrNode p = l;
     while((p -> next) != NULL){
          p = p -> next;
     }
     return p;
}


void printList(List l)
{
     ptrNode p = l -> next;
     int i = 1;
     while(p != NULL){
          printf("第%d个节点:p -> e = %d\tp -> next = %p\n",i,p -> e,p -> next);
          i++;
          p = p -> next;
     }
}

/*
  翻转单链表,每一个节点的next指向前一个节点
 */
void reverse(List l)
{
  List p = l->next;
  List pre = NULL;
  while(p != NULL) {
    List next = p->next;
    p->next = pre;
    pre = p;
    if(next == NULL){
      l->next = p;
      break;
    }
    p = next;
  }
}
