#include "queue.h"

struct Queue{
  element_type * array;
  position head;
  position tail;
  size_t capacity,size;
};

/* 创建一个大小为size的队列 */
ptr_queue make_queue(size_t size)
{
  ptr_queue p = (ptr_queue) malloc(sizeof (queue));
  if(p != NULL){
    p->head = 0;
    p->tail = 0;
    p->size = 0;
    p->capacity = size;
    p->array = (element_type*) malloc(p->capacity * sizeof(size_t));
    if(p->array == NULL)
      exit(1);
  }
  else exit(1);
  return p;
}

/* 入队 */
status enqueue(element_type x,ptr_queue q)
{
  if(isFull(q))
    return false;
  q->array[q->tail] = x;
  q->tail = (q->tail + 1) % q->capacity;
  q->size += 1;
  return true;
}

element_type dequeue(ptr_queue q)
{
  if(isEmpty(q))
    return (element_type)NULL;
  element_type tmp = q->array[q->head];
  q->head = (q->head + 1) % q->capacity;
  q->size -= 1;
  return tmp;
}

status isFull(ptr_queue q)
{
  return q->size == q->capacity;
}

status isEmpty(ptr_queue q)
{
  return q->size == 0;
}
