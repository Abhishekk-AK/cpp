#include<bits/stdc++.h>
using namespace std;

bool checkIthBit(int n, int i) {
    string binary="";

    while(n>0) {
        binary += (n%2==0 ? '0' : '1');
        n /= 2;
    }
    
    if(i >= binary.size())
        return false;

    return binary[i]=='1';
}

//using bit-masking
bool checkIthBitOpt(int n, int i) {
    return (n & (1<<i)) != 0;
}

int main() {
    int a, i;
    cin>>a>>i;

    cout<<checkIthBit(a, i);

    cout<<endl<<checkIthBitOpt(a, i);

    return 0;
}