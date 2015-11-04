#include "list.c"

int main()
{
  List l = CreateList();
  for(int i = 0; i < 100;++i){
    Append(l,i);
  }

  printList(l);
  reverse(l);
  printList(l);

  return 0;
}
