#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int>& nums) {
    int max=nums[0];
    int n=nums.size()-1;

    for (int i=0; i<=n; i++) {
        if(max < nums[i]) {
            max = nums[i];
        }
    }
    return max;
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

    cout<<largestElement(v);

    return 0;
}