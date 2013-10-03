#!/usr/bin/python
import random
import time

def unsorted(length):
    return [random.randrange(0, length*10) for r in xrange(length)]

def partition(l, start, end):
    pivot = l[end]
    top = end
    bottom = start - 1
    done = False

    while not done:
        while not done:
            bottom += 1
            if bottom >= top:
                done = True
                break
            if l[bottom] > pivot:
                l[top] = l[bottom]
                break
    
        while not done:
            top -= 1
            if top <= bottom:
                done = True
                break
            if l[top] < pivot:
                l[bottom] = l[top]
                break

    l[top] = pivot
    return top

def quick_sort(l, start, end):
    if start < end:
        split = partition(l, start, end)
        quick_sort(l, start, split - 1)
        quick_sort(l, split + 1, end)
    else:
        return

if __name__ == '__main__':
    l = unsorted(10)
    print l
    start = 0
    end = len(l) - 1
    start_time = time.time()
    quick_sort(l, start, end)
    end_time = time.time()
    print l
    print end_time-start_time
