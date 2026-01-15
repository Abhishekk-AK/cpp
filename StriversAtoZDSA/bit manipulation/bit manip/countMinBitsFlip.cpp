#include<bits/stdc++.h>
using namespace std;

int minBitsFlip(int n, int m) {
    int count=0;

    int ans = n^m;

    while(ans>0) {
        count += (ans&1);
        ans >>= 1;
    }

    return count;
}


int main() {
    int a,b;
    cin>>a>>b;

    cout<<minBitsFlip(a, b);

    return 0;
}