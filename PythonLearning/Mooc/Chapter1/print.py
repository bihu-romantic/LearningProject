#!/usr/bin/python3
x = "a";
y = "b";

#换行输出
print(x)
print(y)

print('-------');

#不换行输出
print(x, end=' ')
print(y, end=' ')
print()

import sys
print("============Python import mode========")
print('命令行参数为：')
for i in sys.argv:
    print('\n',i)
for j in sys.path:
    print('\n python的路径为', j)
