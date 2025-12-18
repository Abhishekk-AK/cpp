#include<iostream>
#include<vector>
using namespace std;

int searchRotated(vector<int>& nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]==target) {
            return mid;
        }

        
        if(nums[low]<=nums[mid]) {

            if(nums[low]<=target && target<=nums[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        else {

            if(nums[mid]<=target && target<=nums[high]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }

    return -1;
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

    cout<<searchRotated(v, k)<<endl;

    return 0;
}