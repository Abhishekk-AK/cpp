#include<bits/stdc++.h>
using namespace std;

int countDigit(int n) {
    int count=0;

    while(n) {
        int lastDigit=n%10;
        count++;
        n/=10;
    }

    return count;
}

int reverseNumber(int n) {
    int reverseNumber=0;

    while(n>0) {
        int lastDigit=n%10;
        reverseNumber = reverseNumber*10 + lastDigit;
        n/=10;
    }
    return reverseNumber;
}

bool isPalindrome(int n) {
    int num = n;
    int revNum = 0;

    while(n) {
        int lastDigit=n%10;
        revNum = revNum*10+lastDigit;
        n/=10;
    }

    if(revNum == num)
        return true;
    else
        return false;
}

int GCD(int n1,int n2) {
    int gcd=1;

    for(int i=2; i<=min(n1, n2); i++) {

        if(n1%i==0 && n2%i==0)
            gcd=i;
    }
    return gcd;
}


int main() {
    int a = countDigit(2345);
    cout<<a<<'\n';

    int b = reverseNumber(7238);
    cout<<b<<'\n';

    cout<<isPalindrome(121)<<'\n';

    cout<<GCD(12,24)<<'\n';

    return 0;
}