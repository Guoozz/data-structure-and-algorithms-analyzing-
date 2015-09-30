#include "cut-rod.h"


int top_down_cut_rod(int p[],int len)
{
  int r[len+1];
  for(int i = 0; i <= len + 1;++i)
    r[i] = 0;
  int _cut_rod(int p[],int r[],int len);
  return _cut_rod(p,r,len);
}

int _cut_rod(int p[],int r[],int len)
{
  if(r[len] > 0)
    return r[len];
  if(len == 0)
    return 0;
  int max = -1;
  for(int i = 1;i <= len;++i)
    max = MAX(max,p[i] + _cut_rod(p,r,len - i));
  r[len] = max;
  return max;

}
