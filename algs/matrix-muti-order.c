/*
  矩阵链乘问题
  A[i]表示第i个矩阵,其中A[i]的行列数用p[i - 1] * p[i] 表示
  s[i][j] 记录括号位置
  m[i][j] 表示A[i]到 A[j]矩阵链乘的最小代价
  m[i][j] = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j] { if (1 <= i < j < n) (i =< k < j) }
  m[i][j] = 0 { if (i = j) }
*/

//利用带备忘的递归进行求解
#include<stdio.h>

#define INT_MAX 0x07ffffff

int matrix_muti_order(int m[][7],int s[][7],int p[],int i,int j)
{
  if(m[i][j] < INT_MAX)
    return m[i][j];
  int min = INT_MAX;
  for(int k = i; k < j;++k){
    int tmp = matrix_muti_order(m,s,p,i,k) +
      matrix_muti_order(m,s,p,k+1,j) + p[i-1] * p[k] * p[j];
    if(tmp < min){
      min = tmp;
      s[i][j] = k;
      m[i][j] = min;
    }
  }
  return min;
}
void print_matrix_pair(int s[][7],int i,int j)
{
  if(i == j)
    printf("A[%d]",i);
  else
  {
       putchar('(');
       int k = s[i][j];
       print_matrix_pair(s,i,k);
       print_matrix_pair(s,k+1,j);
       putchar(')');
  }

}


int main()
{

  int rows = 7,cols = 7;
  int m[rows][cols];
  int s[rows][cols];
  for(int i = 1;i < rows;++i)
    m[i][i] = 0;
  for(int i = 1;i < rows;++i)
    for(int j = i + 1;j < cols;++j)
      m[i][j] = INT_MAX;p
  int p[] = {5,10,3,12,5,50,6};
  printf("min:%d\n",matrix_muti_order(m,s,p,1,6));
  print_matrix_pair(s,1,6);
  putchar('\n');
}
