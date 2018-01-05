//
//  main.c
//  01-二叉树顺序结构实现
//
//  Created by 朱占龙 on 2018/1/5.
//  Copyright © 2018年 dminfo. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */
#define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */

typedef int Status;
typedef int TElemType;
typedef TElemType SqBiTree[MAX_TREE_SIZE];

typedef struct {
    int level, order;
}Position;

TElemType Nil = 0;

int main(int argc, const char * argv[]) {
    
    return 0;
}
