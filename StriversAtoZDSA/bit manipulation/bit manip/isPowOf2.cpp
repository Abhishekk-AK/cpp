#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n) {
    return n>0 && ( (n&(n-1))==0 );
}


int main() {
    int a,b;
    cin>>a;

    cout<<isPowerOf2(a);

    return 0;
}