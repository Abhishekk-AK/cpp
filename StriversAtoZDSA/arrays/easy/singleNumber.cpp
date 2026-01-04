#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums){
    int n=nums.size();
    int ans=0;

    for(int i=0; i<n; i++) {
        ans ^= nums[i];
    }

    return ans;
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

    cout<<singleNumber(v);

    return 0;
}