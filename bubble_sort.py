#! /bin/usr/python
import random
import time

def unsorted_list(length):
    return [random.randint(0, 2 * length) for r in xrange(length)]

def swap(l, i):
    if l[i] > l[i+1]:
        l[i], l[i+1] = l[i+1], l[i]

def sort(length):
    l = unsorted_list(length)
    print l
    while length > 0:
        length -= 1
        for i in xrange(length):
            swap(l, i)
    print l

if __name__ == "__main__":
    start = time.time()
    sort(10)
    end = time.time()
    print end - start
