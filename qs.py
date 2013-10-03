#!/usr/bin/python
'''shortes quick sort I've ever seen'''
import random
qs = lambda xs : qs( [x for x in xs[1:] if x < xs[0]] ) + [xs[0]] + qs( [x for x in xs[1:] if x > xs[0]] ) if len(xs) > 1 else xs

def unsorted(length):
    return [random.randint(0, length*10) for r in xrange(length)]

if __name__ == '__main__':
    print qs(unsorted(10))

