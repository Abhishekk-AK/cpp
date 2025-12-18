#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lowerBound(vector<int>& nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=n;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]>=target) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    return ans;
}

int upperBound(vector<int>& nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=n;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]>target) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    return ans;
}

pair<int, int> searchRange(vector<int>& nums, int target) {
    int n=nums.size();
    int lb=lowerBound(nums, target);

    if(lb==n || nums[lb]!=target) {
        return {-1,-1};
    }

    return {lb, upperBound(nums, target)-1};
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

    int k;
    cin>>k;

    pair<int, int> ans;
    ans = searchRange(v, k);

    cout<<ans.first<<","<<ans.second;

    return 0;
}