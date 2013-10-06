#!/usr/bin/python
import random
def unsorted(N):
    return [random.randrange(0, N*10) for r in xrange(N)]

class Node:
    left, right, data = None, None, 0
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def insert(self, data):
        if data <= self.data:
            if self.left is None:
                self.left = Node(data)
            else:
                self.left.insert(data)
        else:
            if self.right is None:
                self.right = Node(data)
            else:
                self.right.insert(data)

def sort(L):
    nodes = None
    for item in L:
        if nodes is None:
            nodes = Node(item)
        else:
            nodes.insert(item)
    traverse(nodes)

def traverse(nodes):
    if nodes is None:
        return
    traverse(nodes.left)
    visit(nodes)
    traverse(nodes.right)

sortedL = []
def visit(node):
    sortedL.append(node.data)

if __name__ == '__main__':
    L = unsorted(10)
    print L
    sort(L)
    print sortedL
