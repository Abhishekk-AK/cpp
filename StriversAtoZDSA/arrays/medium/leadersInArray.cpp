#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leaders(vector<int>& nums) {
    vector<int> leaders;
    int n=nums.size();
    int maxi=INT_MIN;

    for(int i=n-1; i>=0; i--) {
        if(nums[i] > maxi) {
            leaders.push_back(nums[i]);
        }
        maxi=max(maxi, nums[i]);
    }

    reverse(leaders.begin(), leaders.end());
    
    // int s=leaders.size();
    // int start=0;
    // int end=s-1;

    // while(start<end) {
    //     int temp = leaders[start];
    //     leaders[start] = leaders[end];
    //     leaders[end] = temp;
    //     start++;
    //     end--;
    // }

    return leaders;
}

int main() {

    int n;
    cin>>n;
    cout<<endl;

    vector<int> v;

    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        v.push_back(x);
    }

    cout<<"Sequence is: ";
    for(auto x: v) {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> ans=leaders(v);
    for(auto x: ans) {
        cout<<x<<" ";
    }

    return 0;
}