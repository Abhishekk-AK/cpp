#include<iostream>
#include<vector>
using namespace std;

int secondLargestElement(vector<int>& nums) {
    int maxi=INT_MIN, second_maxi=INT_MIN;
    int n=nums.size()-1;

    for (int i=0; i<=n; i++) {
        if(maxi < nums[i]) {
            second_maxi = maxi;
            maxi = nums[i];
        }
        else if(second_maxi < nums[i] && nums[i] != maxi) {
            second_maxi = nums[i];
        }
    }
    if(second_maxi == INT_MIN) {
        return -1;
    }
    return second_maxi;
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

    cout<<secondLargestElement(v);

    return 0;
}