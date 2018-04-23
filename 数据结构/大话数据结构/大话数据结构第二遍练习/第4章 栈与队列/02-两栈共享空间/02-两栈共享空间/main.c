//
//  main.c
//  02-两栈共享空间
//
//  Created by 朱占龙 on 2017/12/19.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int SElemType;//数据类型

typedef struct {
    SElemType data[MAXSIZE];
    int top1;//栈1栈顶
    int top2;//栈2栈顶
}SqDoubleStack;



Status InitStack(SqDoubleStack *s) {
    s->top1 = -1;
    s->top2 = MAXSIZE;
    return OK;
}

Status Push(SqDoubleStack *s, int e, int index) {
    if (s->top1 + 1 == s->top2) {
        return ERROR;
    }
    if (index == 1) {
        s->data[++s->top1] = e;
    }else if (index == 2) {
        s->data[--s->top2] = e;
    }
    return OK;
}

Status visit(SElemType e) {
    printf("%d ", e);
    return OK;
}

Status StackTraverse(SqDoubleStack s) {
    int i = 0;
    while (i <= s.top1) {
        visit(s.data[i++]);
    }
    i = s.top2;
    while (i < MAXSIZE) {
        visit(s.data[i++]);
    }
    printf("\n");
    return OK;
}

int StackLength(SqDoubleStack S) {
    return (S.top1 + 1) + (MAXSIZE - S.top2);
}

Status Pop(SqDoubleStack *S, SElemType *e, int index) {
    if (S->top1 == -1 || S->top2 == MAXSIZE) {
        return ERROR;
    }
    if (index == 1) {
        *e = S->data[S->top1--];
    }else if(index == 2) {
        *e = S->data[S->top2++];
    }
    return OK;
}

Status StackEmpty(SqDoubleStack S) {
    if (S.top1 == -1 && S.top2 == MAXSIZE) {
        return TRUE;
    }else {
        return FALSE;
    }
}

Status ClearStack(SqDoubleStack *S) {
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

int main(int argc, const char * argv[]) {
    
    int j;
    SElemType e;
    SqDoubleStack s;
    
    if (InitStack(&s) == OK) {
        printf("初始化成功\n");
        for (j=1; j<=5; j++) {
            Push(&s, j, 1);
        }
        for (j=MAXSIZE; j>=MAXSIZE-2; j--) {
            Push(&s, j, 2);
        }
    }
    
    printf("栈中元素依次为：");
    StackTraverse(s);
    
    printf("当前栈中元素有：%d \n",StackLength(s));
    
    Pop(&s,&e,2);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    
    for (j=6; j<=MAXSIZE-2; j++) {
        Push(&s,j,1);
    }
    
    printf("栈中元素依次为：");
    StackTraverse(s);
    
    printf("栈满否：%d(1:否 0:满)\n",Push(&s,100,1));
    
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    
    return 0;
}
