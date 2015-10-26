#include "cut-rod.h"


int top_down_cut_rod(int len)
{
  int r[MAX_LEN] = {0};
  int _cut_rod(int r[],int len);
  return _cut_rod(r,len);
}

int _cut_rod(int r[],int len)
{
  if(r[len] > 0)
    return r[len];
  if(len == 0)
    return 0;
  int max = -1;
  for(int i = 1;i <= len;++i)//i 代表切割点
    max = MAX(max,p[i] + _cut_rod(r,len - i));
  r[len] = max;
  return max;

}

int _cut_rod_partation(int r[],int len,int c)
{
  if(r[len] > 0)
    return r[len];
  if(len == 0)
    return 0;
  int max = -1;
  for(int i = 1;i < len;++i)//i 代表切割点，若i=len,表示不切割
    {
      int tmp = p[i] + _cut_rod_partation(r,len - i,c) - c;
      if(tmp > max){
        max = tmp;
        s_cut_costs[len] = i;
      }
    }
  if(max < p[len]){
    max = p[len];
    s_cut_costs[len] = len;
  }

  r[len] = max;
  return max;

}

int top_down_cut_rod_with_partation_costs(int len,int c)
{
  int r[MAX_LEN] = {0};
  return _cut_rod_partation(r,len,c);
}
