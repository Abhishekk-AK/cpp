#include<bits/stdc++.h>
using namespace std;

void frequency(int arr[], int size) {

    unordered_map<int, int> mp1;
    for(int i=0; i<size; i++) {
        mp1[arr[i]]++;
    }

    for(auto it: mp1) {
        cout<<it.first<<"->"<<it.second<<endl;
    }
}

void frequentElement(int arr[], int size) {

    int maxFreq=0; int minFreq=INT_MAX;
    int maxEle=0; int minEle=0;

    unordered_map<int, int> mp;
    for(int i=0; i<size; i++) {
        mp[arr[i]]++;
    }

    for(auto it: mp) {

        if(it.second>maxFreq) {
            maxEle=it.first;
            maxFreq=it.second;
        }

        if(it.second<minFreq
           // min element with min freq
           // || (it.second==minFreq && it.first<minEle)
        ) {
            minEle=it.first;
            minFreq=it.second;
        }
    }

    cout<<"MaxFreq: "<<maxFreq<<" MaxEle: "<<maxEle<<endl;
    cout<<"MinFreq: "<<minFreq<<" MinEle: "<<minEle<<endl;
}

int main() {

    int n;
    cout<<"n: ";
    cin>>n;
    int arr[n];
    cout<<"enter array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    map<int, int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }

    for(auto it: mp) {
        cout<<it.first<<"->"<<it.second<<endl;
    }

    int q;
    cout<<"q: "<<endl;
    cin>>q;
    while (q--)
    {
        int num;
        cout<<"enter num: ";
        cin>>num;
        cout<<mp[num]<<endl;
    }


    //frequency count of array elements
    int arr1[7] ={1,2,3,3,3,2,1};
    int size = sizeof(arr1)/sizeof(arr1[0]);

    cout<<"frequency array using unordered map:"<<endl;
    frequency(arr1, size);

    //highest/lowest freq element
    int arr2[] = {1,2,1,3,4,5,2,4,2,3,6,7,8,9};
    int s = sizeof(arr2)/sizeof(arr2[0]);

    cout<<"max and min freq element: "<<endl;
    frequentElement(arr2, s);
    
    return 0;
}