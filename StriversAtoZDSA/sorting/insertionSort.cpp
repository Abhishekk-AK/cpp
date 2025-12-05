#include<iostream>
#include<vector>
using namespace std;

vector<int> insertionSort(vector<int>& nums) {
    int n=nums.size();
    for(int i=0; i<=n-1; i++) {

        int j=i;
        while(j>0 && nums[j]<nums[j-1]) {
            int temp = nums[j-1];
            nums[j-1] = nums[j];
            nums[j] = temp;
            j--;
        }

    }

    return nums;
}

int main() {

    vector<int> v = {9,0,32,2,546,2,11,2,56,8,8,3,987,2};

    vector<int> ans = insertionSort(v);
    for(auto x: ans) {
        cout<<x<<" ";
    }

    return 0;
}