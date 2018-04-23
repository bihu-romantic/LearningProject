#!/usr/bin/env python3
import jieba
def getTxt():
    txt = open('myPaper.txt','r',encoding='utf-8').read()
    return txt
txt = getTxt()

#分割
words = jieba.lcut(txt)

#计数
counts = {}
for word in words:
    if len(word) == 1:
        continue
    else:
        counts[word] = counts.get(word, 0) + 1

countList = list(counts.items())
countList.sort(key=lambda x:x[1], reverse=True)

#打印前10个
for i in range(30):
    word, count = countList[i]
    print('{:<5}:{:>5}次'.format(word, count))