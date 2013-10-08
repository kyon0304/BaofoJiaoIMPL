#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

/*/
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
//*/

struct linklist {
    linklist *next;
    int value;
    linklist(int v, linklist *n):value(v), next(n){}
    ~linklist() {if (next) delete next;}
};

inline int cmp (const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void BucketSort(int *A, int *B, int N, int K) {
    linklist *Bucket[101], *p;
    int i,j,k,M;
    memset(Bucket, 0, sizeof(Bucket));
    M = K/100;
    for (i=0; i<N; i++) {
        k = A[i]/M;
        Bucket[k] = new linklist(A[i], Bucket[k]);
    }
    for (k=j=0; k<=100; k++) {
        i = j;
        for (p=Bucket[k]; p; p=p->next) {
            B[j++] = p->value;
        }
        delete Bucket[k];
        qsort(B+i, j-i, sizeof(B[0]), cmp);
    }
    
}

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
