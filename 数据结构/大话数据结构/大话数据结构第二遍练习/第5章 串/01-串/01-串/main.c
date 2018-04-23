//
//  main.c
//  01-串
//
//  Created by 朱占龙 on 2017/12/24.
//  Copyright © 2017年 dminfo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* 存储空间初始分配量 */

typedef int Status;        /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;    /* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE+1]; /*  0号单元存放串的长度 */

Status StrAssign(String S, char *chars) {
    int i;
    if (strlen(chars) > MAXSIZE) {
        return ERROR;
    }else {
        S[0] = strlen(chars);
        for (i=1; i<S[0]; i++) {
            S[i] = *(chars + i - 1);
        }
        return OK;
    }
}

int StrLength(String S) {
    return S[0];
}

/* 若S为空串,则返回TRUE,否则返回FALSE */
Status StrEmpty(String S) {
    if (S[0] == 0) {
        return TRUE;
    }else {
        return FALSE;
    }
}

/* 由串S复制得串T */
Status StrCopy(String T, String S) {
    int i;
    T[0] = S[0];
    for (i=1; i<=S[0]; i++) {
        T[i] = S[i];
    }
    return OK;
}

Status StrPrint(String S) {
    int i;
    for (i=1; i<=S[0]; i++) {
        printf("%c", S[i]);
    }
    printf("\n");
    return OK;
}

/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
int StrCompare(String S,String T) {
    int i;
    for(i=1;i<=S[0]&&i<=T[0];++i) {
        if(S[i]!=T[i]){
            return S[i]-T[i];
        }
    }
    return S[0]-T[0];
}

/* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
Status Concat(String T,String S1,String S2) {
    int i;
    if (S1[0] + S2[0] <= MAXSIZE) {//未截断
        for (i=1; i<=S1[0]; i++) {
            T[i] = S1[i];
        }
        for (i=0; i<=S2[0]; i++) {
            T[S1[0] + i] = S2[i];
        }
        T[0] = S1[0] + S2[0];
        return TRUE;
    }else {//截断
        for (i=1; i<=S1[0]; i++) {
            T[i] = S1[i];
        }
        for (i=0; i<=MAXSIZE-S1[0]; i++) {
            T[S1[0] + i] = S2[i];
        }
        T[0] = MAXSIZE;
        return FALSE;
    }
}

Status ClearString(String S) {
    S[0] = 0;
    return OK;
}

/* 用Sub返回串S的第pos个字符起长度为len的子串。 */
Status SubString(String Sub, String S, int pos, int len) {
    int i=0;
    if (pos < 1 || pos > S[0] || len < 0 || len > (S[0] - pos + 1)) {
        return ERROR;
    }
    for (i=1; i<=len; i++) {
        Sub[i] = S[pos+i-1];
    }
    Sub[0] = len;
    return OK;
}

/*  初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
/*  操作结果: 从串S中删除第pos个字符起长度为len的子串 */
Status StrDelete(String S, int pos, int len) {
    int i;
    if (pos < 0 || pos > S[0]-len +1 || pos < 0) {
        return ERROR;
    }
    for (i=pos+len; i<=S[0]; i++) {
        S[i-len] = S[i];
    }
    S[0] -= len;
    return OK;
}

/*  初始条件: 串S和T存在,1≤pos≤StrLength(S)+1 */
/*  操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE */
Status StrInsert(String S, int pos, String T) {
    int i;
    if (pos < 1 || pos > S[0]+1) {
        return ERROR;
    }
    if (S[0] + T[0] <= MAXSIZE) {//完全插入
        for (i=S[0]; i>=pos; i--) {
            S[i+T[0]] = S[i];
        }
        for (i=pos; i<pos+T[0]; i++) {
            S[i] = T[i-pos+1];
        }
        S[0] = S[0] + T[0];
        return TRUE;
    }else {//部分插入
        for (i=MAXSIZE; i>=pos; i--) {
            S[i] = T[i-T[0]];
        }
        for (i=pos; i<pos+T[0]; i++) {
            S[i] = T[i-pos + 1];
        }
        S[0] = MAXSIZE;
        return FALSE;
    }
}

/*  T为非空串。若主串S中第pos个字符之后存在与T相等的子串， */
/*  则返回第一个这样的子串在S中的位置，否则返回0 */
int Index(String S, String T, int pos) {
    int i=0;
    int j = 1;
    while (i<S[0] && j<T[0]) {
        if (S[i] == T[j]) {
            i++;
            j++;
        }else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T[0]) {
        return i - T[0];
    }else {
        return 0;
    }
}

int Index2(String S, String T, int pos) {
    int n, m, i;
    String sub;
    if (pos > 0) {
        n = StrLength(S);
        m = StrLength(T);
        i = pos;
        while (i<n-m+1) {
            SubString (sub, S, i, m);
            if (StrCompare(sub,T) != 0) {   /* 如果两串不相等 */
                ++i;
            }else {
                return i;
            }
        }
    }
    return 0;
}

/*  初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关） */
/*  操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串 */
Status Replace(String S,String T,String V) {
    int i=1; /*  从串S的第一个字符起查找串T */
    if(StrEmpty(T)) {/*  T是空串 */
        return ERROR;
    }
    do {
        i=Index(S,T,i); /*  结果i为从上一个i之后找到的子串T的位置 */
        if(i) {/*  串S中存在串T */
            StrDelete(S,i,StrLength(T)); /*  删除该串T */
            StrInsert(S,i,V); /*  在原串T的位置插入串V */
            i+=StrLength(V); /*  在插入的串V后面继续查找串T */
        }
    }while(i);
    return OK;
}

int main(int argc, const char * argv[]) {
    int i,j;
    Status k;
    char s;
    String t,s1,s2;
    k=StrAssign(s1,"abcd");
    if (!k) {
        printf("串长超过MAXSIZE=%d\n", MAXSIZE);
        exit(0);
    }
    
    printf("串长为%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
    
    StrCopy(s2,s1);
    printf("拷贝s1生成的串为: ");
    StrPrint(s2);
    
    k=StrAssign(s2,"efghijk");
    if(!k) {
        printf("串长超过MAXSIZE(%d)\n",MAXSIZE);
        exit(0);
    }
    i=StrCompare(s1,s2);
    if (i<0) {
        s = '<';
    }else if(i==0) {
        s = '=';
    }else {
        s = '>';
    }
    printf("s1为：");
    StrPrint(s1);
    printf("s2为：");
    StrPrint(s2);
    printf("串s1%c串s2\n",s);
    
    k=Concat(t,s1,s2);
    printf("串s1联接串s2得到的串t为: ");
    StrPrint(t);
    if(k==FALSE) {
        printf("串t有截断\n");
    }
    
    ClearString(s1);
    printf("清为空串后,串s1为: ");
    StrPrint(s1);
    printf("串长为%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));

    i=2;
    j=3;
    k=SubString(s2,t,i,j);
    if(k) {
        printf("子串s2为: ");
        StrPrint(s2);
    }
    
    i=4;
    j=2;
    StrDelete(t,i,j);
    printf("删除后的串t为: ");
    StrPrint(t);
    
    i=StrLength(s2)/2;
    StrInsert(s2,i,t);
    printf("在串s2的第%d个字符之前插入串t后,串s2为:\n",i);
    StrPrint(s2);
    
    i=Index(s2,t,1);
    printf("s2的第%d个字母起和t第一次匹配\n",i);
    SubString(t,s2,1,1);
    printf("串t为：");
    StrPrint(t);
    Concat(s1,t,t);
    printf("串s1为：");
    StrPrint(s1);
    Replace(s2,t,s1);
    printf("用串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
    StrPrint(s2);
    
    return 0;
}
