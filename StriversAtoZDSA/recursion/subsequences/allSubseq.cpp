#include<bits/stdc++.h>
using namespace std;

void printSubseq(int idx, vector<int> arr, vector<int>& ds) {
    int n=arr.size();
    if(idx>=n) {
        for(auto x: ds) {
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }

    ds.push_back(arr[idx]);
    printSubseq(idx+1, arr, ds);
    ds.pop_back();
    printSubseq(idx+1, arr, ds);
}

int main() {
    vector<int> arr = {2,3,4,7};
    vector<int> ds;

    printSubseq(0, arr, ds);
    return 0;
}