#include<bits/stdc++.h>
using namespace std;

//m1 using hashing

//m2 bit manipulation
vector<int> singleNumbers(vector<int>& nums){
    int i=0;
    long ans=0;
    while(i<nums.size()) {
        ans ^= nums[i];
        i++;
    }

    //find rightmost set bit and form a digit i.e.(0000100)
    int rightMost = (ans & (ans-1)) ^ ans;

    //concept of buckets
    int b1=0;
    int b2=0;

    i=0;
    while(i<nums.size()) {
        
        if(nums[i] & rightMost) {
            b1 = b1^nums[i];
        }
        else {
            b2 = b2^nums[i];
        }
        i++;
    }

    return {b1, b2};
}

int main() {
    int n;
    vector<int> nums;

    while(cin>>n) {
        nums.push_back(n);
    }

    vector<int> ans = singleNumbers(nums);
    for(auto x:ans) {
        cout<<x<<" ";
    }

    return 0;
}