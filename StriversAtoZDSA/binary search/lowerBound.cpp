#include<iostream>
#include<vector>
using namespace std;

int lowBound(vector<int>& nums, int target){
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

int bSearch(vector<int>& nums, int low, int high, int target) {
    if(low>high) {
        return low;
    }

    int mid = low+(high-low)/2;

    if(target <= nums[mid]) {
        return bSearch(nums, low, mid-1, target);
    }
    else
        return bSearch(nums, mid+1, high, target);
}

int lowerBound(vector<int>& nums, int target) {
    return bSearch(nums, 0, nums.size()-1, target);
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

    cout<<lowBound(v, k)<<endl;

    cout<<lowerBound(v, k)<<endl;

    return 0;
}