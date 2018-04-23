#!/usr/bin/env python3

def getText():
    txt = open('hamlet.txt').read()
    txt = txt.lower()
    for ch in '!"@#$%^&*()+,-./:;<=>?@[\\]_`~{|}':
        txt = txt.replace(ch, ' ')
    return txt

hamletTxt = getText()
words = hamletTxt.split()
counts = {}
for key in words:
    counts[key] = counts.get(key, 0) + 1
items = list(counts.items())
items.sort(key=lambda x:x[1], reverse=True)

for i in range(10):
    word, count = items[i]
    print('{0:<10}{1:>5}次'.format(word, count))

