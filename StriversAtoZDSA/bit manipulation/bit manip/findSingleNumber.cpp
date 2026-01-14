#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums){
    int i=0;
    int ans=0;
    while(i<nums.size()) {
        ans ^= nums[i];
        i++;
    }
    return ans;
}

int main() {
    int n;
    vector<int> nums;

    while(cin>>n) {
        nums.push_back(n);
    }

    cout<<singleNumber(nums);

    return 0;
}