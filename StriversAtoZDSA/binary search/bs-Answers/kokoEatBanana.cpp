#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int findMaxEle(vector<int>& nums) {
    int maxi = INT_MIN;
    int n = nums.size();

    for(int i=0; i<n; i++) {
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}

int totalHours(vector<int>& nums, int hourly) {
    int totalH=0;
    int n=nums.size();

    for(int i=0; i<n; i++) {
        totalH += ceil(double(nums[i])/double(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int>& nums, int hour){
    int n=nums.size();
    int low=1;
    int high=findMaxEle(nums);

    while(low<=high) {
        int mid=low+(high-low)/2;

        int totalH = totalHours(nums, mid);
        if(totalH<=hour) {
            high = mid-1;
        }
        else {
            low = mid+1;
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

    int h;
    cin>>h;

    cout<<minimumRateToEatBananas(v, h)<<endl;

    return 0;
}