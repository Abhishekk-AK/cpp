#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute-force

int majorElement(vector<int>& nums) {
    int majority=-1;
    int n=nums.size();  

    for(int i=0; i<n; i++) {
        int count=0;
        for(int j=0; j<n; j++) {
            if(nums[i]==nums[j]) {
                count++;
            }
        }
        if(count>(n/2)) {
            majority=nums[i];
            break;
        }
    }
    return majority;
}


//better-1

int majorElement1(vector<int>& nums) {
    int n=nums.size();
    int count=1;
    int majority=-1;
    sort(nums.begin(), nums.end());

    for(int i=1; i<n; i++) {
        if(nums[i-1]==nums[i]) {
            count++;
        }
        else {
            count=1;
        }
        if(count>(n/2)) {
            majority = nums[i];
            break;
        }
    }
    return majority;
}

//better-2
//if there is a guaranteed major element
int majorElement2(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    int majority=nums[n/2];

    return majority;
}


//better-3 using hashmap

int majorElement3(vector<int>& nums) {
    int n=nums.size();

    unordered_map<int, int> mp;

    for(int x: nums) {
        mp[x]++;
    }

    for(auto &pair: mp) {
        if(pair.second > n/2) {
            return pair.first;
        }
    }
    return -1;
}


//optimal
int majorityElement(vector<int>& nums) {
    int n=nums.size();
    int count=0;
    int element;

    for(int i=0; i<n; i++) {
        if(count==0) {
            count=1;
            element=nums[i];
        }
        else if(nums[i]==element) {
            count++;
        }
        else {
            count--;
        }
    }

    int count1=0;
    for(int i=0; i<n; i++) {
        if(nums[i]==element) {
            count1++;
        }
    }

    if(count1>(n/2)) {
        return element;
    }

    return -1;
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

    cout<<majorElement(v)<<endl;

    cout<<majorElement1(v)<<endl;

    cout<<majorElement2(v)<<endl;

    cout<<majorElement3(v)<<endl;

    cout<<majorityElement(v);

    return 0;
}