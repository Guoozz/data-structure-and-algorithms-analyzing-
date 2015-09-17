#include "list.c"

int main()
{
  List l = CreateList();
  for(int i = 0; i < 100;++i){
    Append(l,i);
  }
  List l2 = CreateList();
  for(int i = 100; i < 200;++i){
    Append(l2,i);
  }
  printList(l);
  Connect(l,l2);
  printList(l);
  MakeEmpty(l);
  if (isEmpty(l)){
    printf("make empty success\n");
  }
  printList(l);
  return 0;
}
