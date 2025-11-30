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

bool isArmstrong(int n) {

    int length=to_string(n).length();

    int original=n;
    int num=0;

    while(n) {
        int lastDigit=n%10;
        num = num + pow(lastDigit, length);
        n/=10;
    }

    return original==num;
}

vector<int> divisors(int n) {

    vector<int> divisors;
    for(int i=1; i*i<=n; i++) {

        if(n%i==0) {
            divisors.push_back(i);

            if(i!=n/i) {
                divisors.push_back(n/i);   
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

bool isPrime(int n) {
    if(n<=1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    
    for(int i=3; i*i<=n; i+=2) {
        if(n%i==0)
            return false;
    }
    return true;
}

bool isPrimeOpt(int n) {
    if(n<=1)
        return false;
    if(n<=3)
        return true;
    if(n%2==0 || n%3==0)
        return false;
    
    for(int i=5; i*i<=n; i+=6) {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}


int main() {
    int a = countDigit(2345);
    cout<<a<<'\n';

    int b = reverseNumber(7238);
    cout<<b<<'\n';

    cout<<isPalindrome(121)<<'\n';

    cout<<GCD(12,24)<<'\n';

    cout<<isArmstrong(153)<<'\n';

    vector<int> ans = divisors(64);
    
    for(int val : ans)
        cout<<val<<' ';
    
    cout<<'\n';

    cout<<isPrime(83)<<'\n';
    cout<<isPrimeOpt(83)<<'\n';

    return 0;
}