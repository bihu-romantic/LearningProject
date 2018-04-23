#!/usr/bin/env python3
count = input('请输入需要输入的数字个数：')#此处输入4
countVal = eval(count)
inputArr = []
inputVal = input('输入数字，（回车键结束）：')
while countVal > 0 and inputVal != '':
    inputArr.append(inputVal)
    countVal -= 1
    inputVal = input()
print(inputArr)
