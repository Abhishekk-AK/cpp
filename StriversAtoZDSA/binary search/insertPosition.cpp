#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target){
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

    cout<<searchInsert(v, k)<<endl;

    return 0;
}