#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
    int K = 10000;
    int N = 100;
    int* A = new int[N];
    int* B = new int[K];
    for (int i=0; i<N; i++) {
        A[i] = rand()%K + 1;
        printf("%d ", A[i]);
        if (i%10 == 9) {
            printf("\n");
        }
    }
    printf("==========\n");
    BucketSort(A, B, N, K);
    for (int i=0; i<N; i++) {
        printf("%d ", B[i]);
        if (i%10 == 9) {
            printf("\n");
        }
    }
    return 0;
}
