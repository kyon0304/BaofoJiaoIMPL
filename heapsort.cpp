#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void swap(int *array, int i, int j) {
    if (i==j) {
        return;
    }
    array[i] = array[i]^array[j];
    array[j] = array[i]^array[j];
    array[i] = array[i]^array[j];
}

void maxHeapify(int *A, int idx, int heap_size) {
    int child_idx = 2*idx+1;
    if(idx >= heap_size || child_idx >= heap_size) {
        return;
    }
    if(child_idx+1 < heap_size && A[child_idx + 1] > A[child_idx]) {
        child_idx++;
    }
    if(A[idx] < A[child_idx]){
        swap(A, idx, child_idx);
        maxHeapify(A, child_idx, heap_size);
    } 
}

void build_max_heap(int *A, int heap_size) {
    for(int i=(heap_size-2)/2; i>=0; i--){
        maxHeapify(A, i, heap_size);
    }
}

void heapsort(int *A, int heap_size) {
    build_max_heap(A, heap_size);
    for(int i=heap_size-1; i>=0; i--) {
        swap(A, 0, i);
        maxHeapify(A, 0, i);
    }
}

int main() {
    int heap_size = 11;
    int *A = new int[heap_size];
    for(int i=0; i<heap_size; i++) {
        A[i] = rand()%100;
        printf("%d, ", A[i]);
    }
    printf("\n");
    heapsort(A, 11);
    for(int i=0; i<heap_size; i++){
        printf("%d, ", A[i]);
    }
    return 0;
}
