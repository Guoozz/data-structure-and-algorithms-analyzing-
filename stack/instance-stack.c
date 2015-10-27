#include "stack.c"

int main()
{
  stack p = make_stack(10);
  for(int i = 0;!is_full(p) && i < 10;++i)
    push(i,p);
  while(!is_empty(p)){
    printf("%d\n",pop(p));
  }
  return 0;
}
