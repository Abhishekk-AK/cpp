#include<iostream>
#include<vector>
using namespace std;

// //from 1-n(both inclusive)
// int missingNumber(vector<int>& nums) {
//     int xorElem=0;
//     int xorNum=0;
//     int n=nums.size();

//     for(int i=0; i<n-1; i++) {
//         xorElem = xorElem ^ nums[i];
//         xorNum = xorNum ^ (i+1); 
//         cout<<nums[i];
//     }
//     cout<<endl;

//     cout<<xorNum<<" "<<endl;
//     xorNum = xorNum ^ n;
//     cout<<"a"<<xorNum<<"b"<<endl;

//     cout<<xorNum;
//     cout<<xorElem;

//     return xorElem ^ xorNum;
// }


//from 0-n(both Inclusive)
int missingNumber(vector<int>& nums) {
    int xorElem=0;
    int xorNum=0;
    int n=nums.size();

    for(int i=0; i<n; i++) {
        xorElem = xorElem ^ nums[i];
        xorNum = xorNum ^ (i); 
    }

    xorNum = xorNum ^ n;

    return xorElem ^ xorNum;
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

    cout<<missingNumber(v);

    return 0;
}