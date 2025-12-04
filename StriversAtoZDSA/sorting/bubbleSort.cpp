#include<iostream>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int>& nums) {

    for(int i=nums.size()-1; i>=1; i--) {
        
        int swap = 0;

        for(int j=0; j<=i-1; j++) {
            if(nums[j]>nums[j+1]) {
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
                swap=1;
            }
        }
        if(!swap) {
            break;
        }
    }

    return nums;
}

int main() {
    vector<int> v = {1,4,6,32,2,9,3,5,0,9,22,66};

    vector<int>ans = bubbleSort(v);
    for(auto x: ans) {
        cout<<x<<" ";
    }

    return 0;
}