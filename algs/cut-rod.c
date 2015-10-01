#include "cut-rod.h"
#include "below_up_cut_rod.c"
#include "top_down_cut_rod.c"
#include "direct_cut_rod.c"

int cut_rod(int len,int type) //type表示解决钢条切割方法类型
{
  if(type == Direct)                    //直接法求解
    return direct_cut_rod(len);
  else if (type == TopDown)             //自顶向下带备忘的方法求解
    return top_down_cut_rod(len);
  else if (type == BelowUp)             //自底向下的解决办法
    return below_up_cut_rod(len);  //s 记录第一个切割点
  return -1;
}

void partation(int len) //伪递归，其实是个迭代计算过程;先计算长度为len的切割点，然后再计算长度为len-s[len]的切割点
{
  if(len <= 0)
    return ;
  printf("%d,",s[len]);
  partation(len-s[len]);
}

void partation_with_costs(int len)
{
  if(len <= 0)
    return ;
  printf("%d,",s_cut_costs[len]);
  partation_with_costs(len-s_cut_costs[len]);
}


int main()
{
   for(int i = 1; i < 20;++i){
    printf("direct:r[%d]=%d\t",i,cut_rod(i,Direct));
    printf("topdown:r[%d]=%d\t",i,cut_rod(i,TopDown));
    printf("belowup:r[%d]=%d\t",i,cut_rod(i,BelowUp));
    printf("cut with partation costs:r[%d]=%d\n",i,top_down_cut_rod_with_partation_costs(i,5));
    partation(i);
    putchar('\n');
    partation_with_costs(i);
    putchar('\n');
  }

  return 0;
}
