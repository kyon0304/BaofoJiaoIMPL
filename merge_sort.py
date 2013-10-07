#!/usr/bin/python
import random
import time

def unsorted(N):
    return [random.randrange(0, N*10) for r in xrange(N)]

def merge(L, M):
    merged = []
    while L and M:
        if L[0] <= M[0]:
            merged.append(L.pop(0))
        else:
            merged.append(M.pop(0))
    return merged + L + M

def sort(L):
   mid = int(len(L)/2)
   if mid == 0:
       return L
   return merge(sort(L[mid:]), sort(L[:mid]))

def iter_sort(L):
    merged = []
    for i in L:
        merged.append([i])
    while len(merged) > 1:
        merged.append(merge(merged.pop(0), merged.pop(0)))
    return merged.pop()

if __name__ == '__main__':
    L = unsorted(10)
    print L
    start = time.time()
    print sort(L)
    end = time.time()
    print iter_sort(L)
    end2 = time.time()
    print "recursion:", (end-start), "iteration:", (end2 - end)
