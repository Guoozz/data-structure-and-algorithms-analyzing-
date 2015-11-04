#ifndef STACK_H
#define STACK_H

#include<stdlib.h>
#include<stdio.h>


#define STACK_MAX 0x7fffffff
#define true 1
#define false 0
typedef int status;
typedef int element_type;
typedef struct stack* stack;
typedef int position;

stack make_stack(size_t size);
element_type pop(stack s);
void push(element_type item,stack s);
status is_full(stack s);
status is_empty(stack s);

#endif
