#include "stack.h"

struct stack{
  element_type *a;
  size_t capacity;
  position base;
  position top;
};

stack make_stack(size_t size)
{
  stack p = (stack) malloc (sizeof(struct stack));
  if(p == NULL)
    return (stack) p;
  element_type* tmp = (element_type*) malloc (size * sizeof(element_type));
  if(tmp == NULL)
    return (stack) p;
  p->a = tmp;
  p->capacity = size;
  p->base = 0;
  p->top = -1;
  return p;
}

element_type pop(stack s)
{
  if(!is_empty(s))
    return s->a[s->top--];
  return STACK_MAX;
}

void push(element_type item,stack s)
{
  if(!is_full(s))
    s->a[++s->top] = item;
  else printf("stack is full\n");
}

status is_empty(stack s)
{
  return s->top == -1;
}

status is_full(stack s)
{
  return s->top == (position) s->capacity - 1;
}
