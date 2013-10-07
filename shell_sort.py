#!/bin/usr/python
import random

def unsorted(N):
    return [random.randrange(0, N*10) for i in xrange(N)]

STEP = [1, 5, 19, 41, 109]
def step_idx(N):
    for i in xrange(len(STEP)):
        if N < STEP[i]:
            break
    return i

def shell_sort(L):
    idx = step_idx(int(len(L)/2))
    for step in STEP[:idx][::-1]:
        for i in range(step):
            l = L[i::step]
            L[i::step] = insertion_sort(l)

def insertion_sort(L):
    if len(L) <= 1:
        return L
    b = insertion_sort(L[1:])
    m = len(b)
    for i in range(m):
        if L[0] <= b[i]:
            return b[:i] + [L[0]] + b[i:]
    return b +[L[0]]

# from wiki
def shellsort(L):
    N = len(L)
    gap = N / 2
    while gap > 0:
        for i in range(gap, N):
            temp = L[i]
            j = i
            while j >= gap and L[j-gap] > temp:
                L[j] = L[j - gap]
                j = j - gap
            L[j] = temp
        gap /= 2


if __name__ == '__main__':
    L = unsorted(10)
    print L
    shell_sort(L)
    print L
    L = unsorted(10)
    print L
    shellsort(L)
    print L
