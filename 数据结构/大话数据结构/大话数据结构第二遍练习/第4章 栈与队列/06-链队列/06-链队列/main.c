//
//  main.c
//  06-链队列
//
//  Created by 朱占龙 on 2017/12/22.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

//结点结构
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode;
typedef struct QNode *QueuePtr;

//链队列数据
typedef struct {
    QueuePtr front, rear;
}LinkQueue;

Status QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return TRUE;
    }else {
        return FALSE;
    }
}

Status InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (!Q->front) {
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
    return OK;
}

int QueueLength(LinkQueue Q) {
    int i;
    QueuePtr p;
    p = Q.front;
    i = 0;
    while (Q.rear != p) {
        i++;
        p = p->next;
    }
    return i;
}

//入队
Status EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;//指针移位
    return OK;
}

Status visit(QElemType e) {
    printf("%d ", e);
    return OK;
}

Status QueueTraverse(LinkQueue Q) {
    QueuePtr p;
    p = Q.front->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status GetHead(LinkQueue Q, QElemType *d) {
    if (Q.front == Q.rear) {
        return ERROR;
    }
    *d = Q.front->next->data;
    return OK;
}

//出队列
Status DeQueue(LinkQueue *Q, QElemType *d) {
    if (Q->front == Q->rear) {
        return ERROR;
    }
    QueuePtr p;
    p = Q->front->next;
    *d = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->front = Q->rear;
    }
    free(p);
    return OK;
}

Status ClearQueue(LinkQueue *Q) {
    QueuePtr p, q;
    Q->front = Q->rear;
    p = Q->front->next;
    Q->front->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

Status DestroyQueue(LinkQueue *Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

int main(int argc, const char * argv[]) {
    int i;
    QElemType d;
    LinkQueue q;
    i=InitQueue(&q);
    if(i) {
        printf("成功地构造了一个空队列!\n");
    }
    printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
    printf("队列的长度为%d\n",QueueLength(q));
    
    EnQueue(&q,-5);
    EnQueue(&q,5);
    EnQueue(&q,10);
    printf("插入3个元素(-5,5,10)后,队列的长度为%d\n",QueueLength(q));
    
    printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
    printf("队列的元素依次为：");
    QueueTraverse(q);
    
    i=GetHead(q,&d);
    if(i==OK) {
        printf("队头元素是：%d\n",d);
    }
    
    DeQueue(&q,&d);
    printf("删除了队头元素%d\n",d);
    i=GetHead(q,&d);
    if(i==OK) {
        printf("新的队头元素是：%d\n",d);
    }
    
    ClearQueue(&q);
    printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
    DestroyQueue(&q);
    printf("销毁队列后,q.front=%u q.rear=%u\n",q.front, q.rear);
    
    return 0;
}
