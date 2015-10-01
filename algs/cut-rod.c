#include "cut-rod.h"
#include "below_up_cut_rod.c"
#include "top_down_cut_rod.c"
#include "direct_cut_rod.c"

int partation_price(int len,int c); //划分代价
int cut_rod(int,int);

int cut_rod_with_partation_price(int len,int c,int type) //带划分代价的切割代价
{
  return cut_rod(len,type) - partation_price(len,c);
}

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

int partation_price(int len,int c)
{
  int counts = 0;
  while(len > 0){
    if(len != s[len]) //查看是否需要划分
      ++counts;
    len -= s[len];
  }
  return counts * c;
}

int main()
{
  int c = 2; //划分代价
  for(int i = 1; i < 20;++i){
    printf("direct:r[%d]=%d\t",i,cut_rod(i,Direct));
    printf("topdown:r[%d]=%d\t",i,cut_rod(i,TopDown));
    printf("belowup:r[%d]=%d\npartation price:%d\n",i,cut_rod(i,BelowUp),partation_price(i,c));
    partation(i);
    putchar('\n');
  }

  return 0;
}
