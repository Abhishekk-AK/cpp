#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

bool linearSearch(vector<int>& v, int k) {
    int n=v.size();

    for(int i=0; i<n; i++) {
        if(v[i]==k) {
            return true;
        }
    }
    return false;
}

//brute force
int longestCons(vector<int>& nums) {
    int n=nums.size();
    int longest=1;

    if(n==0) {
        return 0;
    }

    for(int i=0; i<n; i++) {
        int count=1;
        int x=nums[i];

        while(linearSearch(nums, x+1)) {
            count++;
            x+=1;
        }
        longest=max(count, longest);
    }
    return longest;
}


//better
int longestConsec(vector<int>& nums) {
    int n=nums.size();
    if(n==0) {
        return 0;
    }

    sort(nums.begin(), nums.end());
    
    int lastSmaller=INT_MIN;
    int count=0;
    int longest=1;

    for(int i=0; i<n; i++) {
        if(nums[i]-1==lastSmaller) {
            count++;
            lastSmaller=nums[i];
        }
        else if(nums[i]!=lastSmaller) {
            count=1;
            lastSmaller=nums[i];
        }

        longest=max(count, longest);
    }

    return longest;
}

//optimal
int longestConsecutive(vector<int>& nums) {
    int longest=1;
    int n=nums.size();
    if(n==0) {
        return 0;
    }
    unordered_set<int> st;

    for(int i=0; i<n; i++) {
        st.insert(nums[i]);
    }

    for(auto it: st) {
        if(st.find(it-1) == st.end()) {
            int count=1;
            int x=it;

            while(st.find(x+1) != st.end()) {
                x=x+1;
                count=count+1;
            }
            longest=max(count, longest);
        }
    }
    return longest;
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

    cout<<longestCons(v)<<endl;
    cout<<longestConsec(v)<<endl;
    cout<<longestConsecutive(v)<<endl;

    return 0;
}