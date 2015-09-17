#include "list.c"

int main()
{
  LIST l = create_list();
  insert(l,3);
  printf("%d\n",l -> next -> x);
  delete_node(l,l->next);
  if(is_empty(l))
    {
      printf("success\n");
    }
  else{
    printf("what the fuck \n");
  }
  return 0;
}
