#!/usr/bin/env python3
from random import random
from time import perf_counter
pi = 0
N = 1000*10000
hits = 0
start = perf_counter()
for i in range(0,N+1):
    x, y = random(), random()
    radius =  pow(x**2+y**2, 0.5)
    if radius <= 1.0:
        hits += 1
pi = 4 * (hits/N)
print('圆周率是：{}'.format(pi))
print('执行时间是：{:.5f}s'.format(perf_counter()-start))