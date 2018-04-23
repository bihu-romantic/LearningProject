//
//  main.c
//  03-线索二叉树
//
//  Created by 朱占龙 on 2018/1/7.
//  Copyright © 2018年 dminfo. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */
typedef int Status;
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;

TElemType Nil = '#';

Status visit(TElemType e)
{
    printf("%c ",e);
    return OK;
}

BiThrTree pre;/* 全局变量,始终指向刚刚访问过的结点 */

/* 按前序输入二叉线索树中结点的值,构造二叉线索树T */
/* 0(整型)/空格(字符型)表示空结点 */
Status CreateBiThrTree(BiThrTree *T) {
    TElemType h;
    scanf("%c",&h);
    if (h == Nil) {
        *T = NULL;
    }else {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if (!(*T)) {
            exit(OVERFLOW);
        }
        (*T) -> data = h;
        CreateBiThrTree(&(*T)->lchild);
        if ((*T)->lchild) {
            (*T)->LTag = Link;
        }
        CreateBiThrTree(&(*T)->rchild);
        if ((*T)->rchild) {
            (*T)->RTag = Link;
        }
    }
    return OK;
}

void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild); /* 递归左子树线索化 */
        if(!p->lchild) /* 没有左孩子 */
        {
            p->LTag=Thread; /* 前驱线索 */
            p->lchild=pre; /* 左孩子指针指向前驱 */
        }
        if(!pre->rchild) /* 前驱没有右孩子 */
        {
            pre->RTag=Thread; /* 后继线索 */
            pre->rchild=p; /* 前驱右孩子指针指向后继(当前结点p) */
        }
        pre=p; /* 保持pre指向p的前驱 */
        InThreading(p->rchild); /* 递归右子树线索化 */
    }
}

Status InOrderThreading(BiThrTree *Thrt,BiThrTree T) {
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
    if (!*Thrt) {
        exit(OVERFLOW);
    }
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt);
    if (!T) {
        (*Thrt)->lchild = *Thrt;
    }else {
        (*Thrt)->lchild=T;
        pre=(*Thrt);
        InThreading(T); /* 中序遍历进行中序线索化 */
        pre->rchild=*Thrt;
        pre->RTag=Thread; /* 最后一个结点线索化 */
        (*Thrt)->rchild=pre;
    }
    return OK;
}

/* 中序遍历二叉线索树T(头结点)的非递归算法 */
Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p=T->lchild; /* p指向根结点 */
    while(p!=T)
    { /* 空树或遍历结束时,p==T */
        while(p->LTag==Link)
            p=p->lchild;
        if(!visit(p->data)) /* 访问其左子树为空的结点 */
            return ERROR;
        while(p->RTag==Thread&&p->rchild!=T)
        {
            p=p->rchild;
            visit(p->data); /* 访问后继结点 */
        }
        p=p->rchild;
    }
    return OK;
}

int main(int argc, const char * argv[]) {
    BiThrTree H,T;
    printf("请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')\n");
    CreateBiThrTree(&T); /* 按前序产生二叉树 */
    InOrderThreading(&H,T); /* 中序遍历,并中序线索化二叉树 */
    
    printf("中序遍历(输出)二叉线索树:\n");
    InOrderTraverse_Thr(H); /* 中序遍历(输出)二叉线索树 */
    printf("\n");
    return 0;
}
