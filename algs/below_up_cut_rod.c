#include "cut-rod.h"

int below_up_cut_rod(int len)
{
  int r[len+1];
  r[0] = 0;
  int max;
  for(int j = 1;j <= len;++j){// 从长度1开始，计算每个长度的最优解，并将解保存在数组r中
    max = -1;
    for(int i = 1;i <= j;++i){
      int tmp = p[i] + r[j - i];
      if(max < tmp){
        max = tmp;
        s[j] = i;
      }
    }
    r[j] = max;
  }
  return r[len];

}
