# 简单单链表
---
###什么是链表？
我不从数学上形式化的定义链表，而只是介绍如何表示链表。在C中，链表由一系列的节点组成，其中每个节点分为两部分：数据部分和指向下一节点的指针。下面是链表的*c代码*表示
```c
structe node {
    ElementType x;
    structe node* next;
    };
```
###可能的操作？
我把对链表的操作分为两类：
. 修改链表
. 遍历链表
####修改链表的操作
```c
    /* 创建一个单链表 */
    ptrNode CreateList(void);
    /* 删除元素为e的节点,该操作只会删除第一个碰到的e元素 */
    void DeleteNode(List l,ElementType e);
    /* 生成一个节点 */
    position CreateNode(ElementType e);
    /* 在位置p后面插入一个元素 */
    void Insert(List l,ElementType e,positon p);
    /* 在结尾添加一个元素 */
    void Append(List l,ElementType e);
    /* 连接两个链表 */
    void Connect(List l1,List l2);
    /* 删除链表 */
    void DeleteList(List l);
    /* 清空链表 */
    void MakeEmpty(List l);
```
####遍历链表的操作
```c
    /* 判断链表是否为空 */
    int isEmpty(List l);
    /* 判断是否是最后一个节点 */
    int isLast(List l);
    /* 返回位置p后面一个元素的位置 */
    position next(List l,position p);
    /* 返回位置p前面一个元素的位置 */
    position previous(List l,position p)
    /* 返回数据部分为e的节点位置 */
    position findElement(List l,ElementType e);
    /* 返回最后一个元素的位置 */
    poistion Last(List l);
    /* 打印链表 */
    void printList(List l);
```
对链表的操作列举的并不全，后续可能会添加新的操作
