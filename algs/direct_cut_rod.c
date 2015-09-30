#include "cut-rod.h"

int direct_cut_rod(int p[],int len)
{
  int direct_cut(int [],int);
  return direct_cut(p,len);
}

int direct_cut(int p[],int len)
{
  if(len == 0)
    return 0;
  int max = -1;
  int MAX(int,int);
  for(int i = 1; i <= len;++i)
    max = MAX(max,p[i] + direct_cut(p,len - i));
  return max;
}
