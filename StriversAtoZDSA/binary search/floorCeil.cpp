#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int floor(vector<int>& nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]<=target) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return ans;
}

//floor with first occcurence 2 pass
int floor2Pass(vector<int>& nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;

    //find the floor
    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]==target) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    if(ans==-1) 
        return -1;

    //find first occurence
    low=0; 
    high=ans;
    int floorVal=nums[ans];

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]==floorVal) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    return ans;
}

//floor with first occurence 1 pass
int floor1Pass(vector<int>& nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(nums[mid]<=target) {
            if(nums[mid]== target) {
                ans=mid;
                high=mid-1;
            }
            else {
                ans = mid;
                low = mid+1;
            }
        }
        else {
            high = mid-1;
        }
    }

    return ans;
}


//ceil always returns the first occurence as binary search runs till the search space
int ceil(vector<int>& nums, int target){
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

    cout<<floor(v, k)<<endl;

    cout<<floor2Pass(v, k)<<endl;

    cout<<floor1Pass(v, k)<<endl;

    cout<<ceil(v, k)<<endl;

    return 0;
}