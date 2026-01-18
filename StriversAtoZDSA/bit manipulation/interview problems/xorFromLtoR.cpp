#include<bits/stdc++.h>
using namespace std;

int xorTillNum(int n) {
    int r=n%4;
    if(r==1) return 1;
    if(r==2) return n+1;
    if(r==3) return 0;
    return n;
}

int findRangeXOR(int l,int r){
    return xorTillNum(l-1) ^ xorTillNum(r);
}

int main() {
    int l, r;
    cin>>l>>r;

    cout<<findRangeXOR(l, r);

    return 0;
}