#include "cut-rod.h"
#include "below_up_cut_rod.c"
#include "top_down_cut_rod.c"
#include "direct_cut_rod.c"

int cut_rod(int len,int type) //type表示解决钢条切割方法类型
{
  int p[] = {0,1,5,8,9,10,17,17,20,24,30}; //钢条价格
  if(type == Direct)                    //直接法求解
    return direct_cut_rod(p,len);
  else if (type == TopDown)             //自顶向下带备忘的方法求解
    return top_down_cut_rod(p,len);
  else if (type == BelowUp)             //自底向下的解决办法
    return below_up_cut_rod(p,len);
  return -1;
}


int main()
{
  for(int i = 1; i < 11;++i){
    printf("direct:r[%d]=%d\t",i,cut_rod(i,Direct));
    printf("topdown:r[%d]=%d\t",i,cut_rod(i,TopDown));
    printf("belowup:r[%d]=%d\n",i,cut_rod(i,BelowUp));
  }
  return 0;
}
