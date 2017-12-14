//
//  main.c
//  02-线性表的链式存储结构
//
//  Created by 朱占龙 on 2017/12/11.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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
    return 0;
}
