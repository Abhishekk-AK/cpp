#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n=nums.size();
    int j=-1;

    for(int i=0; i<n; i++) {
        if(nums[i]==0) {
            j=i;
            break;
        }
    }

    if(j==-1) {
        return;
    }

    for(int i=j+1; i<n; i++) {
        if(nums[i] != 0) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j++;
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

    moveZeroes(v);

    return 0;
}