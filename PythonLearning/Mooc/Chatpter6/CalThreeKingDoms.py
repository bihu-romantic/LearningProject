#!/usr/bin/env python3
import jieba
txt = open('threekingdoms.txt','r',encoding='utf-8').read()
excludes = ['却说','二人','不可','不能','如此','商议','荆州','如何','将军','次日','大喜','左右']
words = jieba.lcut(txt)
counts = {}
for word in words:
    if len(word) == 1:
        continue
    elif word == '诸葛亮' or word == '孔明曰':
        reword = '孔明'
    elif word == '关公' or word == '云长':
        reword = '关羽'
    elif word == '玄德' or word == '玄德曰' or word == '主公':
        reword = '刘备'
    elif word == '孟德' or word == '丞相':
        reword = '曹操'
    else:
        reword = word
        counts[reword] = counts.get(reword, 0) + 1
for key in excludes:
    del counts[key]
items = list(counts.items())
items.sort(key=lambda x:x[1], reverse=True)
for i in range(20):
    word, count = items[i]
    print('{0:<10}{1:>5}次'.format(word, count))