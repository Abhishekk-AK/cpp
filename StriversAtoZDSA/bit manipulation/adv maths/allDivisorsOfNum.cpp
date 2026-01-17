#include<bits/stdc++.h>
using namespace std;

//TC O(sqrt(n)) + O(k*log(k))
//SC O(sqrt(n))
vector<int> divisors(int n){
    vector<int> ans;

    for(int i=1; i*i<=n; i++) {   
        if(n%i==0) {
            ans.push_back(i);
            ans.push_back(n/i);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<int> ans = divisors(n);
    for(auto x:ans) {
        cout<<x<<" ";
    }

    return 0;
}