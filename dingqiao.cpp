/*
 *input: two integer
 *output: their max common divisor and min common multiple
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int findMaxDivisor(int x, int y) {
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    int maxDivisor = y;
    int remainer = x % y;
    while (remainer != 0) {
        maxDivisor = remainer;
        remainer = y % remainer;
        y = maxDivisor;
    }
    return maxDivisor;
}

int findMinMultiple(int x, int y, int maxDivisor) {
    return x * y / maxDivisor;
}

int main(int argc, char** argv) {
    int x, y;
    cout << "input two integer: ";
    cin >> x >> y;
    cout << "get: " << x <<  " "  << y << endl;
    if (x == 0 || y == 0) {
        cout << "0 is not accepted!" << endl;
        return -1;
    }
    int maxDivisor = findMaxDivisor(x, y);
    int minMultiple = findMinMultiple(x, y, maxDivisor);
    cout << "maxDivisor: " << maxDivisor << " minMulitple: " << minMultiple << endl;
    return 0;
}
