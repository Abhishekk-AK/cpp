#include<iostream>
using namespace std;

const int mod = 1e9+7;

int countGoodNum(long long n) {
    long long ans=1;
    
    if(n==1) {
        return ans*5%mod;
    }

    if(n%2==0) {
        ans = (ans*4)%mod;
    }
    if(n%2==1) {
        ans = (ans*5)%mod;
    }

    return ans * countGoodNum(n-1)%mod;
}

int countGoodNumbers(int index, int n) {

    if (index == n) {
        return 1; 
    }

    int result = 0;
    // Even index: Use even digits
    if (index % 2 == 0) {  
        for (int digit : {0, 2, 4, 6, 8}) {
            result = (result + countGoodNumbers(index + 1, n)) % mod;
        }
    } 
    // Odd index: Use prime digits
    else {  
        for (int digit : {2, 3, 5, 7}) {
            result = (result + countGoodNumbers(index + 1, n)) % mod;
        }
    }
    return result;
}

//cleaner version of above
int countGoodNumbersClean(int index, int n) {

    if (index == n) {
        return 1; 
    }

    if (index % 2 == 0) {  
        return (5 * countGoodNumbers(index + 1, n)) % mod;
    } 

    else {  
        return (4 * countGoodNumbers(index + 1, n)) % mod;
    }
}

int main() {
 
    long long n;
    cin>>n;

    cout<<countGoodNum(n)<<endl;

    cout<<countGoodNumbers(0,n)<<endl;

    cout<<countGoodNumbersClean(0,n);
}