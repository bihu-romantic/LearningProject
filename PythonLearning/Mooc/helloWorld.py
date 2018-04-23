#!/usr/bin/python3
#注释以#开头
from doctest import _comment_line
print("Hello,world!"); #这也是注释

'''
这是多行注释
'''
"""
this is comment not one line!
"""
print("this is end!");

#这是python的最大特色，用缩进来表示代码块
if True:
    print("true");
else:
    print("false");

print(r"this is a line with \n");