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
  List l3 = CreateList();
  Append(l3,1);
  Append(l3,2);
  Append(l3,3);
  position p = l3 -> next;
  p = p -> next;
  Insert(l3,888,p);
  printList(l3);
  DeleteNode(l3,888);
  printList(l3);
  DeleteList(l);
  DeleteList(l2);
  DeleteList(l3);
  printf("after delete operation\n");
  printList(l);
  printList(l2);
  printList(l3);

  return 0;
}
