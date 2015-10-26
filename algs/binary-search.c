#include<stdio.h>
/****************************************
递归版本:
 search(a,i,j)
 结束条件 i>j  <=> (middle,middle - 1) or (middle + 1,middle)
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
