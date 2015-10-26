/*
  根据关键字被搜索的频率，求二叉搜索树最小的期望代价.
  我们可以这样描叙这个问题，对于给定的关键字，我们可以用k[1,n]表示关键
  字的集合，有些关键字可 能不在该集合上，因此我们需要d[0,n]这样的伪关键字集合，其中
  d[0]表示小于k[0]的关键字，d[n]表示大于k[n]的关键字。d[i](1 < i < n)表示
  大于k[i]小于k[i+1]的关键字。最后我们用p[i]表示关键字k[i]被搜索到
  的概率,q[i]表示d[i]被搜索到的概率。
  因此，某个结点的代价就是 (depth(i)+1)*r[i] (depth 表示该结点的深度，
  r[i]表示该结点被搜索到的概率),而总的代价就是所有结点的代价和。
  给定关键字集合k[i,j],选定k[r](i<=r<=j)作为根结点，左子树的结点为
  (k[i,r-1],d[i-1,r-1]) 右子树的结点为(k[r+1,j],d[r,j]),其中对于 r=i
  或r=j时只有一个结点d[r],那么总的代价就变成了左子树的代价加上右子树的
  代价，再加上根节点的代价，以及左右子树所有结点深度增加1的代价。
  因此我们可以用e[i,j]表示以关键字k[i,j]和d[i-1,j]为结点的二叉搜索树的最
  小代价。
  e[i,j] = q[i-1] (if j=i-1)
  e[i,j] = min{e[i,r-1]+e[r+1,j]+w(i,j)} (j>=i,i<=r<=j,其中w(i,j) =
  w(i-1,r-1)+w(r+1,j)+p[r]表示结点k[i,j]深度增加1的代价)
  同时我们利用root[i,j]记录k[i,j]根节点的位置r
 */
#include<stdio.h>
#define MIN 100000000000000.0

/* 带备忘的obst算法 */
float bst(float p[],float q[],int root[][100],float w[][100],float e[][100],int i,int j)
{
  if(e[i][j] > 0)
    return e[i][j];
  if(j == i-1){
     return q[i-1];
  }
  else if(j >= i){
    float min = MIN;
    for(int r = i;r <= j;++r){
      float tmp = bst(p,q,root,w,e,i,r-1)+ bst(p,q,root,w,e,r+1,j)+w[i][j];
      if(tmp < min){
        e[i][j] = tmp;
        min = tmp;
        root[i][j] = r;
      }
    }
  }
  return e[i][j];
}

float optimal_bst(float p[],float q[],int n)
{
  float w[100][100],m[100][100]={{0},{0}};
  int root[100][100];
  /* j = i-1 初始化w[i][j] */
  for(int i = 1;i <= n;++i)
    w[i][i-1] = q[i-1];
  /* j >= i 初始化w[i][j] */
  for(int i = 1;i <= n;++i)
    for(int j = i;j <= n;++j)
      w[i][j] = w[i][j-1] + p[j] + q[j];
  float tmp =  bst(p,q,root,w,m,1,n);
  void print_root(int[][100],int,int);
  print_root(root,1,n);
  return tmp;
}

int k[6] = {0,1,2,3,4,5};
float d[6] = {0.2,1.3,2.4,3.5,4.8,5.5};
void print_root(int root[][100],int i,int j)
{
  if(j == i - 1){
    printf("%.2f\t",d[i-1]);
    return ;
  }
  putchar('(');
  printf("root:%d",k[root[i][j]]);
  putchar('(');
  print_root(root,i,root[i][j]-1);
  putchar(')');
  putchar('(');
  print_root(root,root[i][j]+1,j);
  putchar(')');

}

int main()
{
  float p[] = {0,0.15,0.10,0.05,0.10,0.20};
  float q[] = {0.05,0.10,0.05,0.05,0.05,0.10};
  printf("\nbst最小的代价为:%.2f\n",optimal_bst(p,q,5));
  return 0;
}
