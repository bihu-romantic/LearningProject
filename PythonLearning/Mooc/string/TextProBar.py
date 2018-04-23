#!/usr/bin/env python3
import time
print("---------执行开始--------");
scale = 10
for i in range(scale + 1):
    a = '*' * i
    b = '-' * (scale-i)
    c = (i/scale) * 100
    print("{:3.0f}%[{}->{}]".format(c,a,b))
    time.sleep(0.1)
print("---------执行结束--------");

for i in range(101):
    print('\r{:3.0f}%'.format(i), end='')
    time.sleep(0.1)

