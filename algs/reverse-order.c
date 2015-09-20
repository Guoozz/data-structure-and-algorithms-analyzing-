#include<stdio.h>
int counts = 0;
#define len(x) sizeof((x)) / sizeof(int)

/*
  利用归并排序统计一个数组中逆序对的数目，所谓逆序对就是，对于数组a[i,j] 对所有的  i < j 有 a[i] > a[j]
  则称(i,j)为逆序对。利用归并排序可以实现一个O(nlgn)的算法.
  算法伪代码:
  reverse-order(a,p,r)
  if p < r           数组中至少有两个元素
   q = (p + r) / 2
   reverse-order(a,p,q)
   reverse-order(a,q + 1,r)
   merge-counts(a,p,q,r)


 merge-counts(a,p,q,r)
  n1 = q - p + 1
  n2 = r - q
  l[n1] = a[p,q]
  r[n2] = a[q+1,r]
  i = j = 1
  k = p - 1
  counts = 0  逆序对的数目
 该迭代的不变式 :a[p,k] 已排好序，l[i],r[j]分别是各自数组中最小的元素

 while i > n1 or j > n2 // l 或 r 数组其中一个遍历完就结束循环
      if l[i] <= r[j]   // 对于 l[i] <= r[j] 肯定不存在逆序对,
         a[++k] = l[i]
         ++i
      else             // 对于 l[i] > r[j] ，满足逆序对的条件
         a[++k] = r[j]
         j++
         counts++

 if i > n1
   while j <= n2
    a[++k] = r[j]
 else
  while i <= n1
   a[++k] =  l[i]
   counts += n2   //假设 l = {8,9} r = {1,2,3,4,5} a = l + r 则 a 中存在 2 × 5 = 10 个逆序对
 return counts

 */

int merge_counts(int a[],int p,int q,int r);

int reverse_order(int a[],int p,int r)
{
  if(p < r){
    int q = (p + r) / 2;
    reverse_order(a,p,q);
    reverse_order(a,q+1,r);
    return  merge_counts(a,p,q,r);
  }
}

int merge_counts(int a[],int p,int q,int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int left[n1],right[n2];
  int i,j;
  i = j = 0;
  for(i = 0;i < n1;++i)
    left[i] = a[i + p];
  for(i = 0;i < n2;++i)
    right[i] = a[i + q + 1];
  int k = p - 1;
  while(i < n1 || j < n2){
    if(left[i] <= right[j])
      a[++k] = left[i++];
    else{
      a[++k] = right[j++];
      ++counts;
    }
  }
  if(i >= n1){
    while(j < n2)
      a[++k] = right[j++];
  }
  else
    while(i < n1){
      a[++k] = left[i++];
      counts += n2;
    }
  return counts;
}

int main()
{
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  int i = reverse_order(a,0,2);
  printf("%d\n",i);
  for(i = 0;i < len(a);++i)
    printf("%d,",a[i]);
  return 0;
}
