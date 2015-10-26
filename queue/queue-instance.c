#include "queue.c"

int main()
{
  ptr_queue q = make_queue(3);
  while(!isFull(q)){
    element_type item;
    scanf("%d",&item);
    enqueue(item,q);
   }
  while(!isEmpty(q)){
    printf("%d\n",dequeue(q));
  }
  return 0;
}
