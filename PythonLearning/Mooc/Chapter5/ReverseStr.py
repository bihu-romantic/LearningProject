#!/usr/bin/env python3

#通过递归方式实现字符串翻转
#实现递归有两个条件，1：链条，2：基例
def rev(s):
    if s == '':
        return s
    else:
        return rev(s[1:])+s[0]
print(rev('hello World'))