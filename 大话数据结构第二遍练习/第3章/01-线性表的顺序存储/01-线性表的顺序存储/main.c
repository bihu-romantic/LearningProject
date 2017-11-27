//
//  main.c
//  01-线性表的顺序存储
//
//  Created by 朱占龙 on 2017/11/19.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>

#define MAXSIZE 20 /*存储空间初始分配量*/

#define  OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#warning - 注意位置索引和数组索引之间的转换

typedef int Status;/*程序运行的状态*/

typedef int ElemType;/*根据实际情况而定，此处暂定为int类型*/
typedef struct {
    ElemType data[MAXSIZE];/*数组存储数据元素，最大值为MAXSIZE*/
    int length;
}SqList;

/*初始化一个链表*/
Status InitList(SqList *L) {
    L->length = 0;
    return OK;
}

/*判断线性表是否为空*/
Status ListEmpty(SqList L) {
    if (L.length == 0) {
        return TRUE;
    }else {
        return FALSE;
    }
}

/*将线性表清空*/
Status ClearList(SqList *L) {
    L->length = 0;
    return OK;
}
/*获取线性表L中i位置的元素值返回给e*/
Status GetEle(SqList L, int i, int *e) {
    return OK;
}

/*查找与给定值e相等的元素，若成功返回序号，否则返回0*/
int LocateElem(SqList L, int e) {
    int i;
    if (L.length == 0) {
        return 0;
    }
    for (i=0; i<L.length; i++) {
        if (L.data[i] == e) {
            break;
        }
    }
    if (i >= L.length) {
        return 0;
    }
    return i+1;
}

/*在线性表L的第i个位置插入新元素e*/
Status ListInsert(SqList *L, int i, int e) {
    int k;
    if (L->length == MAXSIZE) {
        return ERROR;
    }
    if (i<1 || i>L->length+1) {
        return ERROR;
    }
    if (i <= L->length) {//不在表尾插入
        for (k=L->length-1; k>=i-1; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    
    L->data[i-1] = e;
    L->length++;
    return OK;
}

/*删除线性表L中第i个位置的元素，并用e返回*/
Status ListDelete(SqList *L, int i, int *e) {
    return OK;
}

/*计算线性表的长度*/
int ListLength(SqList L) {
    return L.length;
}

void visti(int i) {
    printf("%d ",i);
}
void print(SqList L) {
    int i;
    for (i=0; i<=L.length-1; i++) {
        visti(L.data[i]);
    }
    printf("\n");
}

Status GetElem(SqList L, int i, int *e) {
    if (L.length==0 || i<1 || i>L.length) {
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

int main(int argc, const char * argv[]) {
    
    SqList L;
    ElemType e;
    Status i;
    int k;
    
    //初始化一个顺序存储的链表
    InitList(&L);
    printf("初始化后L的长度为：%d\n",ListLength(L));
    
    int j;
    for (j=1; j<=5; j++) {
        i = ListInsert(&L, 1, j);
    }
    printf("在表头依次插入五个数据元素后：\n");
    print(L);
    
    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    
    i=ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    
    for(j=1;j<=10;j++) {
        ListInsert(&L,j,j);
    }
    printf("在L的表尾依次插入1～10后：L.data=");
    print(L);
    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    print(L);
    printf("L.length=%d \n",L.length);

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
    
//    k=ListLength(L); /* k为表长 */
//    for(j=k+1;j>=k;j--)
//    {
//        i=ListDelete(&L,j,&e); /* 删除第j个数据 */
//        if(i==ERROR)
//            printf("删除第%d个数据失败\n",j);
//        else
//            printf("删除第%d个的元素值为：%d\n",j,e);
//    }
//    printf("依次输出L的元素：");
//    ListTraverse(L);
//
//    j=5;
//    ListDelete(&L,j,&e); /* 删除第5个数据 */
//    printf("删除第%d个的元素值为：%d\n",j,e);
//
//    printf("依次输出L的元素：");
//    ListTraverse(L);
//
//    //构造一个有10个数的Lb
//    i=InitList(&Lb);
//    for(j=6;j<=15;j++)
//        i=ListInsert(&Lb,1,j);
//
//    unionL(&L,Lb);
//
//    printf("依次输出合并了Lb的L的元素：");
//    ListTraverse(L);

    return 0;
}
