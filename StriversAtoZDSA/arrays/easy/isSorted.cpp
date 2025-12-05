#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& nums){
    int n=nums.size();
    for(int i=1; i<n; i++) {
        if(nums[i] < nums[i-1]) {
            return false;
        }
    }
    return true;
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

    cout<<isSorted(v);

    return 0;
}