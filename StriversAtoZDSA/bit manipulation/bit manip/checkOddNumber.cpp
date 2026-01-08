#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n) {
    if(n%2) {
        return true;
    }
    return false;
}


int main() {
    int a;
    cin>>a;

    cout<<isOdd(a);

    return 0;
}