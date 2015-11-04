#ifndef binary_stack
#define binary_stack

#include "binary-tree.c"

typedef struct stack* stack;

struct stack{
  binary_tree_node * array;
  int top;
  unsigned capacity;
};

stack create_stack(unsigned size)
{
  stack p = (stack) malloc(sizeof(struct stack));
  if(p != NULL) {
    binary_tree_node * tmp = (binary_tree_node *) malloc(size*sizeof(struct binary_tree_node));
    if(tmp != NULL){
      p->array = tmp;
      p->top = -1;
      p->capacity = size;
      return p;
    }
  }
  return (stack) NULL;
}

int is_stack_empty(stack s)
{
  return s->top == -1;
}

int is_stack_full(stack s)
{
  return s->top == (int)s->capacity - 1;
}

binary_tree_node pop(stack s)
{
  if(!is_stack_empty(s)){
    return s->array[s->top--];
  }
  return NULL;
}

void push(binary_tree_node node,stack s)
{
  if(!is_stack_full(s))
    s->array[++s->top] = node;
}

#endif
