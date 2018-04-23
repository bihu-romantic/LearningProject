//
//  main.c
//  03-静态链表
//
//  Created by 朱占龙 on 2017/12/17.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /** 初始空间分配量 */

typedef int Status;
typedef char ElemType;/* ElemType类型根据实际情况而定，这里假设为char */

/** 静态链表的存储结构 */
typedef struct Component{
    ElemType data;
    int cur;//游标
}Component;

typedef Component StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList L) {
    int i;
    for (i=0; i<MAXSIZE-1; i++) {
        L[i].cur = i+1;
    }
    L[MAXSIZE-1].cur = 0;/** 最后一个元素的cur用来存放第一个有值的元素 */
    return OK;
}

int ListLength(StaticLinkList L) {
    int i, j;
    j = 0;
    i = L[MAXSIZE-1].cur;
    while (i) {
        i = L[i].cur;
        j++;
    }
    return j;
}

int Malloc_SSL(StaticLinkList L) {
    int i;
    i = L[0].cur;
    if (L[0].cur) {
        L[0].cur = L[i].cur;
    }
    return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e) {
    int j, k, l;
    if (i < 1 || i > MAXSIZE+1) {
        return ERROR;
    }
    k = MAXSIZE-1;//
    j = Malloc_SSL(L);/* 获得空闲分量的下标 */
    if (j) {
        L[j].data = e;
        for (l=1; l<i; l++) {//
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

void visit(ElemType c) {
    printf("%c ", c);
}

void ListTraverse(StaticLinkList L) {
    int i;
    i = L[MAXSIZE - 1].cur;
    while (i) {
        visit(L[i].data);
        i = L[i].cur;
    }
    printf("\n");
}

/*  将下标为k的空闲结点回收到备用链表 */
void Free_SSL(StaticLinkList L, int k) {
    L[k].cur = L[0].cur;
    L[0].cur = k;
}

Status ListDelete(StaticLinkList L, int i) {
    if (i < 1 || i > ListLength(L)) {
        return ERROR;
    }
    int j, k, l;
    k = MAXSIZE - 1;
    for (l=1; l<i; l++) {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return ERROR;
}

int main(int argc, const char * argv[]) {
    StaticLinkList L;
    Status i;
    i=InitList(L);
    printf("初始化L后：L.length=%d\n",ListLength(L));
    
    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');
    
    printf("\n在L的表头依次插入FEDBA后：\nL.data=");
    ListTraverse(L);
    
    i=ListInsert(L,3,'C');
    printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
    ListTraverse(L);
    
    i=ListDelete(L,1);
    printf("\n在L的删除“A”后：\nL.data=");
    ListTraverse(L);
    
    printf("\n");
    
    return 0;
}
