#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

struct data {
    int key[2];
};

struct linklist {
    int value;
    linklist* next;
    linklist(int v, linklist* n):value(v), next(n){};
    ~linklist() {if (next) delete next;};
};

inline int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void BucketSort(data* A, int N, int K, int y) {
    linklist *Bucket[101], *p;
    int i,j,k,M;
    int *B = new int[N];
    M = K/100 + 1;
    memset(Bucket, 0, sizeof(Bucket));
    for(i=0; i<N; i++) {
        k = A[i].key[y]/M;
        Bucket[k] = new linklist(A[i].key[y], Bucket[k]);
    }
    for(k=j=0; k<100; k++) {
        i = j;
        for (p=Bucket[k]; p; p=p->next) {
            B[j++] = p->value;
        }
        delete Bucket[k];
        qsort(B+i, j-i, sizeof(B[0]), cmp);
    }
    for (i=0; i<N; i++) {
        A[i].key[y] = B[i];
    }
    delete B;
}

void RadixSort(data *A, int N, int K) {
    for (int j=1; j>=0; j--) {
        BucketSort(A, N, K, j);
    }
}

int main() {
    int K = 10000;
    int N = 100;
    data* A = new data[N];
    for (int i=0; i<N; i++) {
        A[i].key[0] = rand()%K + 1;
        A[i].key[1] = rand()%K + 1;
        printf("(%d %d) ", A[i].key[0], A[i].key[1]);
        if (i%10 == 9) {
            printf("\n");
        }
    }
    printf("==========\n");
    RadixSort(A, N, K);
    for (int i=0; i<N; i++) {
        printf("(%d %d) ", A[i].key[0], A[i].key[1]);
        if (i%10 == 9) {
            printf("\n");
        }
    }
    return 0;
}
