#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) { 
    if(n<2) return 0;
    if(n==2 || n==3) return 1;
    if(n%2==0 || n%3==0) return 0;

    for(int i=5; i*i<=n; i+=6) {
        if(n%i==0 || n%(i+2)==0)
            return 0;
    }
    return 1;
}

//TC O(sqrt(n)) + O(k*log(k))
//SC O(sqrt(n))
vector<int> primeFactors(int n){
    vector<int> ans;
    int i;

    for(i=2; i<=n; i++) {   
        if(n%i==0 && isPrime(i)) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<int> ans = primeFactors(n);
    for(auto x:ans) {
        cout<<x<<" ";
    }

    return 0;
}