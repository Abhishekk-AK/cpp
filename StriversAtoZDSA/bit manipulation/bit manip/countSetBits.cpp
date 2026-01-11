#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count=0;

    while(n>0) {
        count += (n&1);
        n >>= 1;
    }

    return count;
}


int main() {
    int a;
    cin>>a;

    cout<<countSetBits(a);

    return 0;
}