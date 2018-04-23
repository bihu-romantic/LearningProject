#!/usr/bin/env python3

def getNum():
    nums = []
    iNumStr = input("请输入数字，按回车键结束:")
    while iNumStr != '':
        nums.append(eval(iNumStr))
        iNumStr = input("请输入数字，按回车键结束")
    return nums

def mean(numbers):
    count = 0.0
    for i in numbers:
        count += i
    return count / len(numbers)

def dev(numbers, mean):#计算方差
    devCount = 0.0
    for i in numbers:
        devCount += (i-mean)**2
    print(devCount,len(numbers))
    return devCount / len(numbers)

def median(numbers):#计算中位数
    sorted(numbers)
    size = len(numbers)
    if size % 2 == 0:
        mid = (numbers[size//2-1] + numbers[size//2])/2
    else:
        mid = numbers[size//2]
    return mid

n = getNum()
m = mean(n)
print('平均值{}方差{:.2f}中位数{}'.format(m,dev(n,m),median(n)))