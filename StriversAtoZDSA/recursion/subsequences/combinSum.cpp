#include<bits/stdc++.h>
using namespace std;

void combination(int ind, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans) {
    if(ind==candidates.size()) {
        if(target==0) {
            ans.push_back(ds);
        }
        return;
    }

    //pick element
    if(candidates[ind]<=target) {
        ds.push_back(candidates[ind]);
        combination(ind, target-candidates[ind], candidates, ds, ans);
        ds.pop_back();
    }

    //not pick element
    combination(ind+1, target, candidates, ds, ans);
}

vector<vector<int>> combinationSum(vector<int>& candites, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    combination(0, target, candites, ds, ans);
    return ans;
}


int main() {
    vector<int> candidates = {2,3,4,7};
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