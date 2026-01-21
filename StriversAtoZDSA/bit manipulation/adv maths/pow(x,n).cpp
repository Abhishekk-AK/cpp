#include<iostream>
using namespace std;

double myPow(double x, int n) {

    long long N=n;
    if(N<0) {
        x = 1/x;
        N = -N;
    }

    double ans=1.0;

    while(N>0) {
        if(N%2==1) {
            ans *= x;
        }
        x *= x;
        N /= 2;
        
    }
    
    return ans;
}

double myPow1(double x, int n) {
    if(n==0) {
        return 1.0;
    }

    long long N=n;
    if(N<0) {
        x = 1/x;
        N = -N;
    }

    double ans=1.0;

    while(N>1) {
        if(N%2==0) {
            x *= x;
            N /= 2;
        }
        else {
            ans *= x;
            N -= 1;
        }
    }
    
    return ans*x;
}


int main() {
    
    double x;
    int n;
    cin>>x>>n;

    cout<<myPow(x,n);
    cout<<endl<<myPow1(x,n);
}