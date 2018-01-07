//
//  main.c
//  02-二叉树的链式存储结构实现
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

typedef int Status;        /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

int index1=1;
typedef char String[24];
String str;
Status StrAssign(String T, char *chars) {
    int i;
    if (strlen(chars) > MAXSIZE) {
        return ERROR;
    }else {
        T[0] = strlen(chars);
        for (i = 1; i<=T[0]; i++) {
            T[i] = *(chars + i -1);
        }
        return OK;
    }
}

typedef char TElemType;
TElemType Nil=' '; /* 字符型以空格符为空 */

typedef struct BiTNode {
    TElemType data;//节点数据
    struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode, *BiTree;


Status InitBiTree(BiTree *T) {
    *T = NULL;
    return OK;
}

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
void CreateBiTree(BiTree *T) {
    TElemType ch;
    ch = str[index1++];
    if (ch == '#') {
        *T = NULL;
    }else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;//生成根节点
        CreateBiTree(&(*T)->lchild);// 构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树
    }
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
int BiTreeEmpty(BiTree T) {
    if (T) {
        return FALSE;
    }else {
        return TRUE;
    }
}

#define ClearBiTree DestroyBiTree

int BiTreeDepth(BiTree T) {
    /* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
    int i, j;
    if (!T) {
        return 0;
    }
    if (T->lchild) {
        i = BiTreeDepth(T->lchild);
    }else {
        i = 0;
    }
    if (T->rchild) {
        j = BiTreeDepth(T->rchild);
    }else {
        j  = 0;
    }
    return i>j ? i+1 :j+1;
}

TElemType Root(BiTree T) {
    if (BiTreeEmpty(T)) {
        return Nil;
    }else {
        return T->data;
    }
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 前序递归遍历T */
void PreOrderTraverse(BiTree T) {
    if (T==NULL) {
        return ;
    }
    printf("%c ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree T) {
    if (T==NULL) {
        return ;
    }
    PreOrderTraverse(T->lchild);
    printf("%c ", T->data);
    PreOrderTraverse(T->rchild);
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序递归遍历T */
void PostOrderTraverse(BiTree T) {
    if (T==NULL) {
        return ;
    }
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
void DestroyBiTree(BiTree *T) {
    if (*T) {
        if ((*T)->lchild) {
            DestroyBiTree(&(*T)->lchild);
        }
        if ((*T)->rchild) {
            DestroyBiTree(&(*T)->rchild);
        }
        free(*T);
        *T = NULL;
    }
}

int main(int argc, const char * argv[]) {
    int i;
    BiTree T;
    TElemType e1;
    InitBiTree(&T);
    
    StrAssign(str,"ABDH#K###E##CFI###G#J##");
    CreateBiTree(&T);
    
    printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    e1=Root(T);
    printf("二叉树的根为: %c\n",e1);
    
    printf("\n前序遍历二叉树:");
    PreOrderTraverse(T);
    printf("\n中序遍历二叉树:");
    InOrderTraverse(T);
    printf("\n后序遍历二叉树:");
    PostOrderTraverse(T);
    
    ClearBiTree(&T);
    printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    i=Root(T);
    if(!i) {
        printf("树空，无根\n");
    }
    return 0;
}
