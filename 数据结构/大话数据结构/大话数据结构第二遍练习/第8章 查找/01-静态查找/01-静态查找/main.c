//
//  main.c
//  01-静态查找
//
//  Created by 朱占龙 on 2018/1/14.
//  Copyright © 2018年 dminfo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;//Status是函数的类型,其值是函数结果状态代码，如OK等
int F[100];//斐波那契数列

/* 无哨兵顺序查找，a为数组，n为要查找的数组个数，key为要查找的关键字 */
int Sequential_Search(int *a, int n, int key) {
    int i;
    for (i=1; i<=n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return 0;
}

/* 有哨兵顺序查找 */
int Sequential_Search2(int *a, int n, int key) {
    int i;
    a[0] = key;
    i = n;
    while (a[i] != key) {
        i--;
    }
    return i;
}

/* 折半查找 */
int Binary_Search(int *a, int n, int key) {
    int low, high, mid;
    low = 0;
    high = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key < a[mid]) {
            high = mid - 1;
        }else if(key > a[mid]) {
            low = mid + 1;
        }else {
            return mid;
        }
    }
    return 0;
}

/* 插值查找 */
int Interpolation_Search(int *a, int n, int key) {
    int low, high, mid;
    low = 1;
    high = n;
    while (low <= high) {
        mid = low + (high - low) * ((key - a[low]) / (a[high] - a[low]));
        if (key < a[mid]) {
            high = mid - 1;
        }else if(key > a[mid]) {
            low = mid + 1;
        }else {
            return mid;
        }
    }
    return 0;
}

/* 斐波那契查找 */
int Fibonacci_Search(int *a, int n, int key) {
    int low,mid,high,i,k = 0;
    low = 1;
    high = n;
    while (n > F[k]-1) {
        k++;
    }
    for (i=n; i<F[k]-1; i++) {
        a[i] = a[n];
    }
    while (low < high) {
        mid=low+F[k-1]-1;
        if (key<a[mid]) {
            high=mid-1;
            k=k-1;
        }else if(key>a[mid]) {
            low = mid + 1;
            k = k-2;
        }else {
            if (mid <= n) {
                return mid;
            }else {
                return n;
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int a[MAXSIZE+1],i, result;
    int arr[MAXSIZE] = {0,1,16,24,35,47,59,62,73,88,99};
    for (i=0; i<=MAXSIZE; i++) {
        a[i] = i;
    }
    
    result = Sequential_Search(a,MAXSIZE,MAXSIZE);
    printf("Sequential_Search:%d \n",result);
    
    result=Sequential_Search2(a,MAXSIZE,1);
    printf("Sequential_Search2:%d \n",result);
    
    result=Binary_Search(arr,10,62);
    printf("Binary_Search:%d \n",result);
    
    result=Interpolation_Search(arr,10,62);
    printf("Interpolation_Search:%d \n",result);
    
    F[0] = 0;
    F[1] = 1;
    for (i=2; i<=MAXSIZE; i++) {
        F[i] = F[i-2] + F[i-1];
    }
    result=Fibonacci_Search(arr,10,62);
    printf("Fibonacci_Search:%d \n",result);
    
    return 0;
}
