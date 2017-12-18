//
//  main.c
//  01-顺序栈
//
//  Created by 朱占龙 on 2017/12/18.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType;//数据类型

/* 顺序栈结构 */
typedef struct {
    SElemType data[MAXSIZE];
    int top;
}SqStack;

Status InitStack(SqStack *S) {
    S -> top = -1;
    return OK;
}

Status Push(SqStack *S, int value) {
    if (S->top > MAXSIZE-1) {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = value;
    return OK;
}

void visit(int value) {
    printf("%d ", value);
}

void StackTraverse(SqStack S) {
    int i;
    i = S.top;
    while ( i >= 0) {
        visit(S.data[i]);
        i--;
    }
    printf("\n");
}

Status Pop(SqStack *S, SElemType *e) {
    if (S->top == -1) {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}

Status StackEmpty(SqStack S) {
    if (S.top == -1) {
        return TRUE;
    }else {
        return FALSE;
    }
}

void GetTop(SqStack S, SElemType *e) {
    if (S.top == -1) {
        return;
    }
    *e = S.data[S.top];
}

int StackLength(SqStack S) {
    return S.top + 1;
}

Status ClearStack(SqStack *S) {
    if (S->top == -1) {
        return ERROR;
    }
    S->top = -1;
    return OK;
}

int main(int argc, const char * argv[]) {
    
    int j;
    SqStack S;
    int e;
    if (InitStack(&S) == OK) {
        for (j=1; j<=10; j++) {
            Push(&S, j);
        }
    }
    
    printf("栈中元素依次为：");
    StackTraverse(S);
    
    Pop(&S,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(S));
    StackTraverse(S);
    
    GetTop(S,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(S));
    
    ClearStack(&S);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(S));
    
    return 0;
}
