#!/usr/bin/env python3

# 斐波那契数列的递归实现
def fibnaci(n):
    if n <= 1:
        return 1
    else:
        return fibnaci(n - 1) + fibnaci(n - 2)


for i in range(10):
    print(fibnaci(i))
