#include<stdio.h>
#include<stdlib.h>


typedef struct binary_tree_node* binary_tree_node;
typedef struct tree* tree;


typedef struct stack* stack;

struct stack{
  binary_tree_node * array;
  int top;
  unsigned capacity;
};



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

struct binary_tree_node{
  int ele;
  binary_tree_node left;
  binary_tree_node right;
};

struct tree{
  int info;
  binary_tree_node root;
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
tree create_tree()
{
  tree root = (tree) malloc(sizeof(struct tree));
  if(root != NULL){
    root->root = NULL;
    root->info = 0x7fffffff;
  }
  return root;
}

void traverse(tree t)
{
  binary_tree_node tmp = t->root;
  if(tmp == NULL)
    return;
  printf("root$ %d\n",tmp->ele);
  t->root = tmp->left;
  traverse(t);
  t->root = tmp->right;
  traverse(t);
  t->root = tmp;
}

void traverse_no_recusive(tree t)
{
  stack s = create_stack(20);
  push(t->root,s);
  while(!is_stack_empty(s)) {
    binary_tree_node root = pop(s);
    if(root != NULL){
      printf("root$ %d\n",root->ele);
      if(root->right != NULL)
        push(root->right,s);
      if(root->left != NULL)
        push(root->left,s);
    }
  }
}

binary_tree_node create_tree_node(int ele,binary_tree_node left,binary_tree_node right)
{
  binary_tree_node node = (binary_tree_node) malloc(sizeof(struct binary_tree_node));
  if(node != NULL) {
    node->left = left;
    node->right = right;
    node->ele = ele;
  }
  return node;
}

int main()
{
  tree t = create_tree();
  binary_tree_node n1 = create_tree_node(1,NULL,NULL),n2 = create_tree_node(2,NULL,NULL);
  binary_tree_node n3 = create_tree_node(3,n1,n2);
  t->root = n3;
  traverse(t);
  traverse_no_recusive(t);
  return 0;
}
