#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count=0;
    int maxi=0;
    int n=nums.size();

    for(int i=0; i<n; i++) {
        if(nums[i]==1) {
            count++;
        }
        else {
            count=0;
        }
        maxi = max(count, maxi);
    }
    return maxi;
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

    cout<<findMaxConsecutiveOnes(v);

    return 0;
}