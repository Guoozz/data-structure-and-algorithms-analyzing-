#include<stdio.h>
#include"doubly-linked-list.c"

int main()
{
  doubly_list head = create_doubly_list();
  int max;
  scanf("%d",&max);
  for(int i = 0;i < max;++i){
    node tmp = create_node(i);
    insert(tmp,head);
  }
  reverse_doubly_list(head);
  node p = head->head;
  while(p != NULL){
    printf("%d\n",p->x);
    p = p->next;
  }
  return 0;
}
