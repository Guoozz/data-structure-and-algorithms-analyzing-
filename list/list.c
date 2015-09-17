#include "list.h"

struct node
{
  element_type x;
  ptrNode next;
};

int is_empty(LIST L)
{
     position p = L -> next;
     return p -> next == NULL;
}

position create_node(element_type x)
{
  position p = (position) malloc(sizeof(struct node));
  if(p == NULL)
  {
       printf("error malloc failed");
       exit(0);
  }
  p -> x = x;
  return p;
}

position create_list()
{
     position header = create_node(default);
     header->next = NULL;
     return header;
}

void insert(position p,element_type x)
{
     position tmp = create_node(x);
     tmp -> next = p -> next;
     p -> next = tmp;
}

position previous(LIST L,position p)
{
     position tmp = L -> next;
     while(tmp != NULL && tmp != p)
     {
          tmp = tmp -> next;
     }
     return tmp;
}
void delete_node(LIST L,position p)
{
     position tmp = p -> next;
     previous(L,p) -> next = tmp;
     free(tmp);
}
