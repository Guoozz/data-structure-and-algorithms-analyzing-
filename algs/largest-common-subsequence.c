#include<stdio.h>
#include<stdlib.h>
#define LEN(x) (int) sizeof(x)/sizeof(int)
/*
  最长公共子序列问题
  m[i,j] 表示序列X,Y最长公共子序列的长度，其中i,j分别为X,Y中序列的数目
  递归定义:
  m[i,j] = 0 {if i=0 or j=0}
  m[i,j] = m[i-1,j-1]+1 {if x[i]=x[j] and i,j>0}
  m[i,j] = max{m[i-1,j],m[j,i-1]} {if x[i]!=x[j] and i,j>0}
 */

/* 带备忘的最长公共子序列算法 */

int largest(int x[],int y[],int m[][100],int i,int j)
{
  if(i == -1 || j == -1)
    return 0;
  if(m[i][j] > -1)
    return m[i][j];
  if(x[i] == y[j])
    m[i][j]= largest(x,y,m,i-1,j-1)+1;
  else if(largest(x,y,m,i-1,j) >= largest(x,y,m,i,j-1))
    m[i][j] = largest(x,y,m,i-1,j);
  else
    m[i][j] = largest(x,y,m,i,j-1);
  return m[i][j];
}

/* 不使用额外的表打印最长公共子序列 */
void print_largest(int x[],int y[],int m[][100],int i,int j)
{
  if(i == -1 || j == -1)
    return ;
  if(x[i] == y[j]){
    if(m[i][j] == m[i-1][j-1] + 1){
      print_largest(x,y,m,i-1,j-1);
      printf("%d\t",x[i]);
    }
  }
  else if(m[i][j] == m[i-1][j])
    print_largest(x,y,m,i-1,j);
  else
    print_largest(x,y,m,i,j-1);
}

int main()
{
  /* 求 X,Y的最长公共子序列 */
  int x[] = {1,0,2,3,7,1111,333,444,43,33};
  int y[] = {99,0,32,98,2,3,7,33};
  int m[100][100];
  for(int i = 0;i < 100;++i)
    for(int j = 0;j < 100;++j)
      m[i][j] = -1;
  printf("%d\n",largest(x,y,m,LEN(x),LEN(y))); //LEN(x) 为数组x的长度
  print_largest(x,y,m,LEN(x),LEN(y));
  putchar('\n');
  return 0;
}
