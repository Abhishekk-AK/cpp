#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    int maxi=INT_MIN;

    for(int i=0; i<n; i++) {
        sum += nums[i];

        if(sum>maxi) {
            maxi=sum;
        }

        if(sum<0) {
            sum=0;
        }
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

    cout<<maxSubArray(v);

    return 0;
}