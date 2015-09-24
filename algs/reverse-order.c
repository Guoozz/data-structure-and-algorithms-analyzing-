#include<stdio.h>
#include<stdlib.h>
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



 merge-counts(a,p,q,r) //
  n1 = q - p + 1
  n2 = r - q
  l[n1] = a[p,q]
  r[n2] = a[q+1,r]
  i = j = 1
  k = p
  counts = 0  逆序对的数目
 该迭代的不变式 :a[p,k] 已排好序，l[i],r[j]分别是各自数组中最小的元素
 i = j = 0
 while i > n1 and j > n2 // l 或 r 数组其中一个遍历完就结束循环
      if l[i] <= r[j]   // 对于 l[i] <= r[j] 肯定不存在逆序对,
         a[k++] = l[i]
         ++i
      else             // 对于 l[i] > r[j] ，满足逆序对的条件
         a[k++] = r[j]
         j++
         counts = n1 - i;

 if i > n1
   while j <= n2
    a[++k] = r[j]
 else
  while i <= n1
   a[++k] =  l[i]

 return counts

 */

int merge_counts(int a[],int p,int q,int r);
void print_array(int a[],int p,int r);

int reverse_order(int a[],int p,int r)
{
  if(p < r){
    int q = (p + r) / 2;
    reverse_order(a,p,q);
    reverse_order(a,q + 1,r);
    return  merge_counts(a,p,q,r);
  }
  return 0;
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
  int k = p;
  i = j = 0;
  while(i < n1 && j < n2){
    if(left[i] <= right[j])
      a[k++] = left[i++];
    else{
      a[k++] = right[j++];
      counts += n1 - i;  //n1 - i 为 left数组中剩余的元素
    }
  }
  while(j < n2)
      a[k++] = right[j++];
  while(i < n1)
      a[k++] = left[i++];
  return counts;
}

void print_array(int a[],int p,int r)
{
  for(int i = p;i <= r;++i)
    {
      printf(" %d,",a[i]);
    }
  printf("\n");
}


/* 直接发求逆序对 */
int r(int a[],int hi)
{
  int c = 0;
  for(int i = 0; i < hi;++i)
    for(int j = i + 1;j <= hi;++j)
      if(a[i] > a[j]) ++c;
  return c;
}

int main()
{
  int a[100] = {0};
  int l;
  scanf("%d",&l);
  for(int i = 0;i < l;++i)
    a[i] = rand() % 100 ;
  int  c = r(a,l - 1);
  reverse_order(a,0,l - 1);
  printf("c = %d \ncounts = %d\n",c,counts);
  print_array(a,0,l - 1);
  return 0;
}
