#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

void BucketSort(int* A, int* B, int N, int K) {
    int *C = new int[K+1];
    memset(C, 0, sizeof(int)*(K+1));
    int i, j, k;
    for (i = 0; i < N; i++) {
        C[A[i]]++;
    }
    for (i=j=0; i<=K; i++,j=k) {
        for (k=j; k<j+C[i]; k++) {
            B[k] = i;
        }
    }
}

int main() {
    int K = 100;
    int N = 10;
    int* A = new int[N];
    int* B = new int[K];
    for (int i=0; i<N; i++) {
        A[i] = rand()%K + 1;
        printf("%d ", A[i]);
    }
    printf("\n==========\n");
    BucketSort(A, B, N, K);
    for (int i=0; i<N; i++) {
        printf("%d ", B[i]);
    }
    return 0;
}
