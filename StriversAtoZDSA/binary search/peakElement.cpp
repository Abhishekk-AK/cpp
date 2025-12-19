#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//return peak index
int peakElement(vector<int>& nums){
    int n=nums.size();
    int low=1;
    int high=n-2;

    if(nums[0]>nums[1]) {
        return 0;
    }

    if(nums[n-1]>nums[n-2]) {
        return n-1;
    }

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) {
            return mid;
        }
        else if(nums[mid]<nums[mid+1]) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return -1;
}

int peakElement1(vector<int>& nums) {
    int n=nums.size();
    int low=0;
    int high=n-1;

    while(low<high) {
        int mid=low+(high-low)/2;

        if(nums[mid]>nums[mid+1]) {
            high=mid;
        }
        else {
            low=mid+1;
        }
    }
    return low;
}

int main() {
    int n;
    cin>>n;

    vector<int> v;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        v.push_back(x);
    }
    cout<<endl;

    cout<<"Sequence is: ";
    for(auto x: v) {
        cout<<x<<" ";
    }
    cout<<endl; 

    cout<<peakElement(v)<<endl;

    cout<<peakElement1(v)<<endl;

    return 0;
}