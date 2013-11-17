#include <stdio.h>

int LIS(int* d, int n){
    int* B = new int[n];
    int left,right,mid, len=1;
    B[0] = d[0];
    for (int i = 1; i < n; i++) {
        left = 0; right = len;
        while (left < right) {
            mid = (left + right) / 2;
            if (B[mid] < d[i]) left = mid + 1;
            else right = mid - 1;
        }
        B[left] = d[i];
        if (left > mid) len++;
    }
    delete[] B;
    return len;
}

int main(){
    int d[9] = {2,1,3,5,6,7,9,8,10};
    printf("%d\n", LIS(d, 9));
}
