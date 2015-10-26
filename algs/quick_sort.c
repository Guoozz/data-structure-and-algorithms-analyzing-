//采用分治法进行快速排序
#include<stdio.h>
#include<stdlib.h>

int partion(int a[],int lo,int hi); //找出数组a[lo,hi]的划分点

void quick_sort(int a[],int lo,int hi)
{
  if(lo < hi){               //至少有两个元素才进行划分
    int p = partion(a,lo,hi);
    quick_sort(a,lo,p - 1);
    quick_sort(a,p + 1,hi);
  }
}

int partion(int a[],int lo,int hi)
{
  int x = a[hi];
  int i = lo - 1;
  void exchange(int a[],int i,int hi);
  for(int j = lo;j < hi;++j)
    if(a[j] <= x)
      exchange(a,++i,j);
  ++i;
  exchange(a,i,hi);
  return i;
}

void exchange(int a[],int lo,int hi)
{
  int tmp = a[lo];
  a[lo] = a[hi];
  a[hi] = tmp;
}

int main()
{
  int a[100]={0};
  for(int i = 0;i < 100;++i)
    a[i] = rand() % 100;
  quick_sort(a,0,99);
  for(int i = 0;i < 99;++i){
    printf("%d\t",a[i]);
    if((i + 1) % 10 == 0)
      printf("\n");
    }
  printf("\n");
  return 0;
}
