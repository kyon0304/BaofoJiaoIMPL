#!/usr/bin/python

import random

def unsorted(length):
    return [random.randrange(0, length*10) for r in xrange(length)]

def select(L):
    minus = L[0]
    idx = 0
    i = 0
    for item in L:
        if item < minus:
            minus = item
            idx = i
        i += 1
    return minus, idx

def sort(L):
    count = len(L)
    for i in xrange(count):
        temp = L[i]
        L[i], idx = select(L[i:])
        L[idx + i] = temp
    print L

if __name__ == '__main__':
    l = unsorted(10)
    print l
    sort(l)
