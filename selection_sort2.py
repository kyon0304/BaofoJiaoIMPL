#!/usr/bin/python
''' from others '''
def selection_sort(L):
    N = len(L)
    min_idx = 0
    for i in xrange(N-1):
        for j in xrange(i+1, N):
            if L[min_idx] > L[j]:
                min_idx = j
        if min_idx != i:
            L[min_idx], L[i] = L[i], L[min_idx]

import random
def unsorted(N):
    return [random.randint(0, N*10) for r in xrange(N)]

if __name__ == '__main__':
    l = unsorted(10)
    print l
    selection_sort(l)
    print l
