#include "queue.c"

int main()
{
  ptr_queue q = make_queue(1);
  while(!isFull(q)){
    element_type item;
    scanf("%d",&item);
    enqueue(item,q);
   }
  return 0;
}
