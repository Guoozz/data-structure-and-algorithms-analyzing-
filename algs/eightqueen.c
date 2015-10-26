/*

Acked-by: Guoozz <csguozhen@gmail.com>

  在不尝试参考其他资料的情况下,试着解决8皇后问题.
  我试着从其他方面去解决这个问题,所谓地从其他方面,就
  是不直接写出该问题的解法.
  假设我用一个序列来表示八皇后的排列,例如序列
  a={0,1,2,3,4,5,6,7},其中a[i](0<=i<=7)表示第i列皇后的
  位置为a[i].那么自然而然的问题是,给定一个皇后的位置k以及列号col,
  我们如何去判定该皇后的位置是否安全(安全指的是该皇后与其他皇后
  不在同一行,同一列,以及同一对角线上).
  实现该判定的一个很简单的算法就是,将a[0,col-1]与该皇后的位置逐个
  进行判定.
  然而这里需要面对的问题是,该怎样表示所有安全的皇后序列.
*/

#include<stdio.h>

typedef int position;
typedef int bool;
#define true 1
#define false 0

bool is_same_row(position a,position k);
bool is_same_diagonal(position a, int i,position k,int j);

/* 判断一个皇后的位置是否安全 */
bool is_safe(int a[],position k,int col)
{
  for(int i = 0;i <= col-1;++i){
    if( is_same_row(a[i],k) ||  is_same_diagonal(a[i],i,k,col))
      return false;
  }
  return true;
}

/* 判断是否在同一行上 */
bool is_same_row(position a,position k)
{
  return a == k;
}

/* 判断是否在一个对角线上,实际上可以抽象为判定2个点是否在直线 y = x +
   b 或 y = -x + b 上
*/
bool is_same_diagonal(position a,int i,position k,int j)
{
  return (a-i == k-j) || (a+i == k+j);
}


/* 递归的定义k皇后问题,先求k-1皇后问题,然后将第k列皇后的位置加入 */

queen_list n_queen(int n)
{
  if(n == 0)
    return NULL;
  queen_list l =  n_queen(n-1);
  for(int i = 0;i < n;++i){
    if(is_safe(l,i,n))
      join_queen_list(l,i,n);
  }
}
