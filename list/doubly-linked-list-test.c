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
  node p = head->head;
  while(p != NULL){
    printf("%d\n",p->x);
    p = p->next;
  }
  for(int i = 0;i <= max;++i){
    node p = search(i,head);
    if(p != NULL)
      printf("%d\n",p->x);
  }
  return 0;
}
