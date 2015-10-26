/*
  空间效率 O(n) 时间效率 O(n*n) 二项系数算法
 */
#include<stdio.h>
long binomial_coefficient(int n,int m)
{
  if(m == 0 || m == n)
    return 1;
  long row[n+1],tmp[n+1]; // 保存上一行的计算结果
  int i,j;
  for(i = 2;i < n;++i){
    row[i] = 0;
    tmp[i] = 0;
  }
  row[1] = 1;
  tmp[i] = 1;
  row[0] = 1;
  tmp[0] = 1;
  row[n] = 1;
  for(i = 2;i <= n;++i){
    for(j = 1; j < i;++j){


int main()
{
  int n,m;
  long binomial_coefficient(int,int);
  while(1){
    scanf("%d%d",&n,&m);
    printf("c(%d,%d)=%ld\n",n,m,binomial_coefficient(n,m));
  }
  return 0;
}
