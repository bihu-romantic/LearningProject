//
//  main.c
//  02-线性表的链式存储结构
//
//  Created by 朱占龙 on 2017/12/11.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

Status InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    if (!(*L)) {
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

/** 返回链表长度 */
int ListLength(LinkList L) {
    int i = 0;
    LinkList p = L -> next;
    while (p) {
        p = p->next;
        i++;
    }
    return i;
}

/** 在指定位置i处插入元素e */
Status ListInsert(LinkList *L, int i, ElemType e) {
    int j = 1;
    LinkList p, s;
    p = (*L);
    while (p && j < i) {
        ++j;
        p = p -> next;
    }
    if (!p || j > i) {
        return ERROR;
    }
    s = (LinkList) malloc(sizeof(Node));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return OK;
}

Status print(ElemType e) {
    printf("%d,", e);
    return OK;
}

Status ListTraverse(LinkList L) {
    LinkList p = L->next;
    while (p) {
        print(p->data);
        p = p -> next;
    }
    printf("\n");
    return OK;
}

/** 判断线性表是否为空 */
Status ListEmpty(LinkList L) {
    if (L -> next) {
        return FALSE;
    }else {
        return TRUE;
    }
}

Status ClearList(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

Status GetElem(LinkList L, int i, int *e) {
    int j;
    LinkList p;
    p = L->next;
    j=1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p -> data;
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(LinkList L, int e) {
    int i = 0;
    LinkList p = L -> next;
    while (p) {
        ++i;
        if (p -> data == e) {
            return i;
        }
        p = p -> next;
    }
    return 0;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int index, ElemType *e) {
    LinkList p, q;
    int i = 1;
    p = (*L);
    while (p && i < index) {
        ++i;
        p = p -> next;
    }
    if (!(p->next) || i > index) {
        return ERROR;
    }
    q = p -> next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
Status CreateListHead(LinkList *L, int n) {
    LinkList p;
    int i;
    srand(time(0));//初始化随机数种子
    *L = (LinkList) malloc(sizeof(Node));
    (*L)->next = NULL;
    for (i=0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p ->next = (*L) -> next;
        (*L)->next = p;
    }
    return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
Status CreateListTail(LinkList *L, int n) {
    LinkList p, q;
    int i;
    *L = (LinkList) malloc(sizeof(Node));
    (*L) -> next = NULL;
    q = *L;
    for (i=0; i<n; i++) {
        p = (LinkList) malloc(sizeof(Node));
        p -> data = rand() % 100 + 1;
        q -> next = p;
        q = p;
    }
    q -> next = NULL;
    return OK;
}

int main(int argc, const char * argv[]) {
    LinkList L;
    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    
    for (j=1; j<=5; j++) {
        i = ListInsert(&L, 1, j);
    }
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);
    
    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    
    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    
    for(j=1;j<=10;j++)
        ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);
    
    printf("ListLength(L)=%d \n",ListLength(L));
    
    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n",ListLength(L));
    
    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    
    for(j=3;j<=4;j++) {
        k=LocateElem(L,j);
        if(k) {
            printf("第%d个元素的值为%d\n",k,j);
        }else {
            printf("没有值为%d的元素\n",j);
        }
    }
    printf("依次输出L的元素：");
    ListTraverse(L);
    
    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);
    
    printf("依次输出L的元素：");
    ListTraverse(L);
    
    i=ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L);
    
    i=ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L);
    
    return 0;
}
