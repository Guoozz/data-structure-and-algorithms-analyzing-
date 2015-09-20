#include<stdio.h>
/****************************************
递归版本:
 search(a,i,j)
 if i > j 数组为空 return
 m = middle(a,i,j);计算数组a[i,j]中间位置
 search(a,i,middle - 1) if a[midlle] > v
 search(a,middle+1,j) if a[midlle] < v
 else return middle
*****************************************/

int search(int a[],int v,int i,int j)
{
  if(i > j) return -1;
  int  middle = (i + j) / 2;
  if(v < a[middle]) return search(a,v,i,middle - 1);
  else if(v > a[middle]) return search(a,v,middle + 1,j);
  else return middle;
}


int search_iter(int a[],int v,int i,int j)
{
  while(i <= j){
    int middle = (i + j) / 2;
    if(v < a[middle])
      j = middle - 1;
    else if (v > a[middle]) i = middle + 1;
    else return middle;
  }
  return -1;
}
