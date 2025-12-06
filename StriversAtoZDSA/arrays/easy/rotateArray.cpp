#include<iostream>
#include<vector>
using namespace std;

void rotateArrayByOne(vector<int>& nums) {
    int temp=nums[0];
    int n=nums.size();

    for(int i=1; i<n; i++) {
        nums[i-1]=nums[i];
    }
    nums[n-1]=temp;
    
    for(auto x: nums) {
        cout<<x<<" ";
    }
}

void reverse(vector<int>& v, int low, int high) {
    while(low<high) {
        int temp = v[low];
        v[low] = v[high];
        v[high] = temp;
        low++;
        high--;
    }
}

void rotateArray(vector<int>& nums, int k) {
    int temp=nums[0];
    int n=nums.size();
    k = k%n;

    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);
    reverse(nums, 0, n-1);
    
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

    vector<int> v_copy = v;

    rotateArrayByOne(v);
    cout<<endl;

    int k;
    cin>>k;
    rotateArray(v_copy, k);

    return 0;
}