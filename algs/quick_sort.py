import random

#快速排序的python实现

def quick_sort(l):
    return quick_sort_helper(l,0,len(l) - 1)

def quick_sort_helper(l,left,right):
    if right > left:
        pos = partition(l,left,right)
        quick_sort_helper(l,left,pos-1)
        quick_sort_helper(l,pos+1,right)

#循环不变式，l[left:pos+1]为小于l[right]的元素,
#           l[pos+1:i] 为大于等于l[right]的元素
#           l[i:]为将要比较的元素
def partition(l,left,right):
    #随机选择一个元素进行划分
    rad = random.randint(left,right)
    exchange(l,rad,right)

    last = l[right]
    pos = left - 1
    i = 0

    for i in range(left,right+1):
        if l[i] < last:
            pos += 1
            exchange(l,pos,i)

    pos += 1
    exchange(l,pos,i)

    return pos

def exchange(l,i,j):
    tmp = l[i]
    l[i] = l[j]
    l[j] = tmp
