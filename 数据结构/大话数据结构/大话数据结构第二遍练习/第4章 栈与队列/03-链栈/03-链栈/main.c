//
//  main.c
//  03-链栈
//
//  Created by 朱占龙 on 2017/12/19.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;

//链栈的数据结构
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode;
typedef struct StackNode *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
}LinkStack;

Status InitStack(LinkStack *S) {
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!S->top) {
        return ERROR;
    }
    S->top = NULL;
    S->count = 0;
    return OK;
}

Status Push(LinkStack *S, int j) {
    LinkStackPtr s = (LinkStackPtr) malloc(sizeof(StackNode));
    s->data = j;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

void visit(int value) {
    printf("%d ", value);
}

void StackTraverse(LinkStack s) {
    LinkStackPtr p = s.top;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

Status StackEmpty(LinkStack S) {
    if (S.count == 0) {
        return TRUE;
    }else {
        return FALSE;
    }
}

Status Pop(LinkStack *S, SElemType *e) {
    LinkStackPtr p;
    if (StackEmpty(*S)) {
        return ERROR;
    }
    *e = S->top->data;
    p = S->top;
    S->top = p->next;
    S->count--;
    free(p);
    return OK;
}

Status GetTop(LinkStack S, SElemType *e) {
    *e = S.top->data;
    return OK;
}

Status ClearStack(LinkStack *S) {
    LinkStackPtr p, q;
    p = S->top;
    while (p) {
        q = p;
        p =  q->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

int StackLength(LinkStack S) {
    return S.count;
}

int main(int argc, const char * argv[]) {
    int j;
    SElemType e;
    LinkStack s;
    if (InitStack(&s) == OK) {
        for (j=0; j<=10; j++) {
            Push(&s, j);
        }
    }
    
    printf("栈中元素依次为：");
    StackTraverse(s);
    
    Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    
    return 0;
}
