#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int>& nums, int target) {
    int n=nums.size();
    for(int i=0; i<n; i++) {
        if(nums[i]==target) {
            return i;
        }
    }
    return -1;
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

    int target;
    cin>>target;
    cout<<linearSearch(v, target);

    return 0;
}