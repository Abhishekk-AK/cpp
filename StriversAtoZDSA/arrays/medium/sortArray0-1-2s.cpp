#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//dutch national flag algo
void sortZeroOneTwo(vector<int>& nums) {

    int n=nums.size();
    int low=0;
    int mid=0;
    int high=n-1;

    for(int i=0; i<n; i++) {
        if(nums[mid]==0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid]==1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    
    for(auto x: nums) {
        cout<<x<<" ";
    }
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

    sortZeroOneTwo(v);

    return 0;
}