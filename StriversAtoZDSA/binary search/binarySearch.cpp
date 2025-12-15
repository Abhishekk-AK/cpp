#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]<target) {
            low = mid+1;
        }
        else if(nums[mid]>target) {
            high = mid-1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int bSearch(vector<int>& nums, int low, int high, int target) {
    if(low>high) {
        return -1;
    }

    int mid = low+(high-low)/2;

    if(target == nums[mid]) {
        return mid;
    }
    else if (target > nums[mid]) {
        return bSearch(nums, mid+1, high, target);
    }

    return bSearch(nums, low, mid-1, target);
}

int binarySearchRec(vector<int>& nums, int target) {
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

    cout<<binarySearch(v, k)<<endl;

    cout<<binarySearchRec(v, k)<<endl;

    return 0;
}