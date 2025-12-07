#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n=nums.size();

    int posIndex=0; 
    int negIndex=1;

    vector<int> ans(n,0);

    for(int i=0; i<n; i++) {
        if(nums[i] < 0) {
            ans[negIndex] = nums[i];
            negIndex+=2;
        }
        else {
            ans[posIndex] = nums[i];
            posIndex+=2;
        }
    }
    return ans;
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

    vector<int> ans = rearrangeArray(v);
    for(auto x: ans) {
        cout<<x<<" ";
    }

    return 0;
}