#include<iostream>
#include<vector>
using namespace std;

int maxProd(vector<int>& nums) {
    int n=nums.size();

    int maxProd=nums[0];

    for(int i=0; i<n; i++) {
        int prod=1;
        for(int j=i; j<n; j++) {
            prod *= nums[j];
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
}

int maxiProd(vector<int>& nums) {
    int maxProd=INT_MIN;
    int n=nums.size();

    int pre=1; int suff=1;

    for(int i=0; i<n; i++) {
        if(pre==0) pre=1;
        if(suff==0) suff=1;

        pre *= nums[i];
        suff *= nums[n-1-i];

        maxProd = max(maxProd, max(pre, suff));
    }
    return maxProd;
}

int main() {

    int n;
    cin>>n;
    cout<<endl;

    vector<int> v;

    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        v.push_back(x);
    }

    cout<<"Sequence is: ";
    for(auto x: v) {
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<maxProd(v)<<endl;

    cout<<maxiProd(v)<<endl;

    return 0;
}