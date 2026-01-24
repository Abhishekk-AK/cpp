#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& v) {
    if(v.empty()) return 0;

    int i=0, j=1;

    int n=v.size();
    while(j < n) {
        if(v[i]==v[j]) {
            j++;
        }
        else {
            i++;
            swap(v[i], v[j]);
            j++;
        }
    }

    return i+1;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr;
    int a;
    for(int i=0; i<n; i++) {
        cin>>a;
        arr.push_back(a);
    }

    for(int i=0; i<n; i++) {
        cout<<arr[i];
    }

    cout<<endl<<"No. of unique elements."<<removeDuplicates(arr);

    return 0;
}