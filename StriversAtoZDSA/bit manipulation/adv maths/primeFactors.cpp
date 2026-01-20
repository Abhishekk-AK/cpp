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

//TC O(sqrt(n)) + O(n)
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

//TC O(sqrt(n) * 2 * sqrt(n))
vector<int> primeFactors1(int n) {
    vector<int> ans;

    for(int i=1; i*i<=n; i++) {
        if(n%i==0) {
            if(isPrime(i))
                ans.push_back(i);
            if(n/i!=i) {
                if(isPrime(n/i)) 
                    ans.push_back(n/i);
            }
        }
    }
    
    return ans;
}

//TC O(sqrt(n) * log(n))
vector<int> primeFactors2(int n) {
    vector<int> ans;

    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            ans.push_back(i);
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1) ans.push_back(n);
    
    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<int> ans = primeFactors(n);
    for(auto x:ans) {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> ans1 = primeFactors1(n);
    for(auto x:ans1) {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> ans2 = primeFactors2(n);
    for(auto x:ans2) {
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}