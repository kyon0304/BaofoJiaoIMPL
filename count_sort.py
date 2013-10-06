#!/bin/usr/python
import random

def unsorted(N):
    return [random.randrange(0, N*10) for r in xrange(N)]

def maxValue(L):
    maxV = L[0]
    for item in L:
        if item > maxV:
            maxV = item
    return maxV

def count_sort(L):
    countL = [0] * (maxValue(L) + 1)
    for item in L:
        countL[item] += 1

    sortedL = []
    for i in xrange(len(countL)):
        sortedL.extend([i]*countL[i])
    return sortedL

if __name__ == '__main__':
    l = unsorted(10)
    print l
    print count_sort(l)
