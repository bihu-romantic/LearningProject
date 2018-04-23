//
//  main.c
//  05-顺序队列
//
//  Created by 朱占龙 on 2017/12/21.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int QElemType;

//顺序队列数据结构
typedef struct {
    int front;
    int rear;
    QElemType data[MAXSIZE];
} SqQueue;

Status InitQueue(SqQueue *q) {
    q->front = 0;
    q->rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue q) {
    if (q.front == q.rear) { /* 队列空的标志 */
        return TRUE;
    }else {
        return FALSE;
    }
}

Status EnQueue(SqQueue *q, QElemType d) {
    if ((q->rear + 1) % MAXSIZE == q->front) {//队列满标记
        return ERROR;
    }
    q->data[q->rear] = d;
    q->rear = (q->rear+1) % MAXSIZE;
    return OK;
}

int QueueLength(SqQueue q) {
    return (q.rear-q.front + MAXSIZE) % MAXSIZE;
}

Status DeQueue(SqQueue *q, QElemType *d) {
    if (q->front == q->rear) {
        return ERROR;
    }
    *d = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return OK;
}

Status visit(QElemType e) {
    printf("%d ", e);
    return OK;
}

Status QueueTraverse(SqQueue q) {
    int i;
    i = q.front;
    while ((i+q.front) != q.rear) {
        visit(q.data[i]);
        i = (i+1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}

Status GetHead(SqQueue q, QElemType *d) {
    if (q.front == q.rear) {
        return ERROR;
    }
    *d = q.data[q.front];
    return OK;
}

Status ClearQueue(SqQueue *q) {
    q->front = q->rear = 0;
    return OK;
}

int main(int argc, const char * argv[]) {
    int j;
    int i=0, l;
    QElemType d;
    SqQueue Q;
    InitQueue(&Q);
    printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    
    do{
        d=i+100;
        if(d==-1)
            break;
        i++;
        EnQueue(&Q,d);
    }while(i<MAXSIZE-1);
    
    printf("队列长度为: %d\n",QueueLength(Q));
    printf("现在队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    printf("连续%d次由队头删除元素,队尾插入元素:\n",MAXSIZE);
    
    for(l=1;l<=MAXSIZE;l++)
    {
        DeQueue(&Q,&d);
        printf("删除的元素是%d,插入的元素:%d \n",d,l+1000);
        /* scanf("%d",&d); */
        d = l+1000;
        EnQueue(&Q,d);
    }
    l=QueueLength(Q);
    
    printf("现在队列中的元素为: \n");
    QueueTraverse(Q);
    
    printf("共向队尾插入了%d个元素\n",i+MAXSIZE);
    if(l-2>0)
        printf("现在由队头删除%d个元素:\n",l-2);
    while(QueueLength(Q)>2)
    {
        DeQueue(&Q,&d);
        printf("删除的元素值为%d\n",d);
    }
    
    j=GetHead(Q,&d);
    if(j) {
        printf("现在队头元素为: %d\n",d);
    }
    ClearQueue(&Q);
    printf("清空队列后, 队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    
    return 0;
}
