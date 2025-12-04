#include<iostream>
#include<vector>
using namespace std;

vector<int> selectionSort(vector<int>& nums) {
    
    for(int i=0; i<nums.size()-1; i++) {
        int min=i;

        for(int j=i+1; j<nums.size(); j++) {
            if(nums[j]<nums[min]) {
                min=j;
            }
        }

        int temp=nums[min];
        nums[min]=nums[i];
        nums[i]=temp;
    }

    return nums;
}

int main() {
    vector<int> v = {1,4,6,9,2,3,0,66,22,99};
    vector<int> ans = selectionSort(v);

    for(auto x: ans) {
        cout<<x<<" ";
    }
    cout<<endl;

    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}