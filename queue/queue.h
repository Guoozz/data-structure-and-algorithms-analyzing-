#ifndef QUEUE_H
#define QUEUE_H

#include<stdlib.h>
#include<stdio.h>

#define false 0
#define true 1
typedef struct Queue queue;
typedef struct Queue * ptr_queue;
typedef int element_type;
typedef int status;
typedef int position;

ptr_queue make_queue(size_t size);
status enqueue(element_type x,ptr_queue q);
element_type dequeue(ptr_queue q);
status isFull(ptr_queue q);
status isEmpty(ptr_queue q);

#endif
