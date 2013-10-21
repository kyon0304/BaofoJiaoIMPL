#include <iostream>
using namespace std;

bool VerifyListofBST(int* l, int length) {
    if(!l|| length < 0) {
        return false;
    }
    int n = 0;
    int root = *(l+length-1);
    while(*(l+n) < root){
        n++;
    }
    int j = n;
    while(j < (length-1)) {
        if(*(l+j) < root) {
            return false;
        }
        j++;
    }

    bool left = true;
    if(n > 0) {
        left = VerifyListofBST(l, n);
    }
    bool right = true;
    if(j < (length-1)) {
        right = VerifyListofBST(l+n, length-n);
    }

    return (left&&right);
}

int main(){
    int list[] = {5, 9, 6, 9, 11, 10, 8};
    for(int i = 0; i < 7; i++) {
        cout << list[i] << "    ";
    }
    cout << endl;
    cout << VerifyListofBST(list, 7) << endl;
}
