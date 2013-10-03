#!/usr/bin/python
import random
import time

def unsorted(length):
    return [random.randrange(0, length*10) for r in xrange(length)]

def quicksort(l):
    if len(l) > 0:
        pivot = random.randint(0, len(l)-1)
        elements = l[:pivot] + l[pivot+1:]
        left = [e for e in elements if e <= l[pivot]]
        right = [e for e in elements if e > l[pivot]]
        l = quicksort(left) + [l[pivot]] + quicksort(right)
    return l

def qsort(L):
    if len(L) < 2:
        return L
    pivot = random.choice(L)
    small = [i for i in L if i < pivot]
    pivots = [i for i in L if i == pivot]
    large = [i for i in L if i > pivot]
    return qsort(small) + pivots + qsort(large)

def compare(a, b):
    if a < b:
        return -1
    if a == b:
        return 0
    if a > b:
        return 1

def distribute(bins, L, fn):
    for item in L:
        bins[fn(item)].append(item)

def qqsort(L):
    if len(L) < 2:
        return L
    pivot = random.choice(L)
    bins = {-1:[], 0:[], 1:[]}
    distribute(bins, L, lambda x : compare(x, pivot))
    return qqsort(bins[-1]) + bins[0] + qqsort(bins[1])


if __name__ == '__main__':
    l = unsorted(10)
    print l
    start = time.time()
    l = quicksort(l)
    end = time.time()
    qsort(l)
    end2 = time.time()
    qqsort(l)
    end3 = time.time()
    print l
    print "sublist time:", (end - start), "originlist time:", (end2 - end), "go through once:", (end3 - end2)
