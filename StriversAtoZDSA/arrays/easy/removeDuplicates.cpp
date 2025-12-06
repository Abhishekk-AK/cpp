#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }

    // //actually deletes the duplicate elements
    // for(int i=1; i<=nums.size()-1; ) {
    //     if(nums[i]==nums[i-1]) {
    //         nums.erase(nums.begin()+i);
    //     }
    //     else {
    //         i++;
    //     }
    // }
    // return nums.size();

    int k=1;
    for(int i=1; i<nums.size(); i++) {
        if(nums[i]==nums[i-1]) {
        }
        else {
            nums[k]=nums[i];
            k++;
        }
    }
    return k;

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

    int ans = removeDuplicates(v);
    cout<<ans<<endl;

    cout<<"After: ";
    for(auto x: v) {
        cout<<x<<" ";
    }

    return 0;
}