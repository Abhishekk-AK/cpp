#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> countFrequencies(vector<int>& nums) {
    unordered_map<int, int> mp;

    for(int x : nums) {
        mp[x]++;
    }

    vector<vector<int>> result;
    result.reserve(mp.size());

    for(auto &p : mp) {
        result.push_back({p.first, p.second});
    }
    //sort(result.begin(), result.end());

    return result;
}

int mostFrequentElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    int mostFreq=0;
    int mostFreqEle=INT_MAX;

    for(int i=0; i<nums.size(); i++) {
        mp[nums[i]]++;
    }

    for(auto it: mp) {
        if(it.second>mostFreq 
            || (it.second==mostFreq && it.first<mostFreqEle)
        ) {
            mostFreq = it.second;
            mostFreqEle = it.first;
        }
    }

    return mostFreqEle;
}

int main() {

    vector<int> v;
    v = {1,9,2,2,3,4,4,4,4,2,2,5,5,5,5};

    vector<vector<int>> freq = countFrequencies(v);
    for(const auto &v: freq) {
        cout<<"Element: "<<v[0]<<", Freq: "<<v[1]<<endl;
    }

    cout<<mostFrequentElement(v)<<endl;

    return 0;
}