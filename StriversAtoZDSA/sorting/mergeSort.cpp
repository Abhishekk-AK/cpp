#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;

    int left=low;
    int right=mid+1;

    while(left <= mid && right <= high) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    for(int i=low; i<=high; i++) {
        nums[i] = temp[i-low];
    }
    
}

void msort(vector<int>& nums, int low, int high) {
    if(low >= high) {
        return;
    }

    int mid = (low+high)/2;

    msort(nums, low, mid);
    msort(nums, mid+1, high);
    merge(nums, low, mid, high);

}

void mergeSort(vector<int>& nums) {
    msort(nums, 0, nums.size()-1);
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

    cout<<"Before sorting: ";
    for(auto x: v) {
        cout<<x<<" ";
    }
    cout<<endl;

    mergeSort(v);

    cout<<"After sorting: ";
    for(auto x: v) {
        cout<<x<<" ";
    }

    return 0;
}