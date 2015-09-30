#ifndef CUT_ROD_H
#define CUT_ROD_H

#define Direct 0
#define TopDown 1
#define BelowUp 2
#define MAX_LEN 100

#include<stdio.h>
#include<stdlib.h>

int MAX(int a,int b){return (a >= b)? a:b;};
int direct_cut_rod(int p[],int len);
int top_down_cut_rod(int p[],int len);
int below_up_cut_rod(int p[],int len);


#endif
