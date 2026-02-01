#include<bits/stdc++.h>
using namespace std;

void combination(int ind, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans) {
    if(target==0) {
        ans.push_back(ds);
        return;
    }

    if(ind==candidates.size() || target<0) {
        return;
    }

    //pick element
    ds.push_back(candidates[ind]);
    combination(ind+1, target-candidates[ind], candidates, ds, ans);
    ds.pop_back();

    //skip duplicates
    while(ind+1<candidates.size() && candidates[ind]==candidates[ind+1]) ind++;

    //not pick element
    combination(ind+1, target, candidates, ds, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    combination(0, target, candidates, ds, ans);
    return ans;
}


int main() {
    vector<int> candidates = {2,3,4,7,4,3,2,5};
    int target=7;

    vector<vector<int>> ans = combinationSum(candidates, target);
    for(auto x: ans) {
        for(auto y: x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}