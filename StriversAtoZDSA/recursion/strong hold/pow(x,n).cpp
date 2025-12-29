#include<iostream>
using namespace std;

double myPow(double x, int n) {
    if(n==0) {
        return 1;
    }

    if(n==1) {
        return x;
    }

    if(n%2==0) {
        return myPow(x*x, n/2);
    }
    
    return x*myPow(x, n-1);
}

int main() {
 
    int x,n;
    cin>>x>>n;

    cout<<myPow(x,n);
}