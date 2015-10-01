#ifndef CUT_ROD_H
#define CUT_ROD_H

#define Direct 0
#define TopDown 1
#define BelowUp 2
#define MAX_LEN 100

#include<stdio.h>
#include<stdlib.h>

int p[] = {0,1,5,8,9,10,17,17,20,24,30}; //钢条价格
int s[MAX_LEN];                          //记录钢条切割的第一个切割点

int MAX(int a,int b){return (a >= b)? a:b;};
int direct_cut_rod(int len);
int top_down_cut_rod(int len);
int below_up_cut_rod(int len);


#endif
