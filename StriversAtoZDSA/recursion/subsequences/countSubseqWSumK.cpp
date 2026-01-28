#include<bits/stdc++.h>
using namespace std;

int countSubseqWithSumK(int idx, vector<int> arr, int k) {

    if(k==0)
        return 1;

    if(k<0 || idx==arr.size())
        return 0;

    return countSubseqWithSumK(idx+1, arr, k-arr[idx]) + countSubseqWithSumK(idx+1, arr, k);
    
}


int main() {
    vector<int> arr = {1,2,3,4,5};
    int target=6;

    cout<<countSubseqWithSumK(0, arr, target);
    return 0;
}