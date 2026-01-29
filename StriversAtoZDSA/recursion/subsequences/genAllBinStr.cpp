#include<iostream>
#include<vector>
#include<string>
using namespace std;

void helper(int n, string s, vector<string>& v) {
    if(s.length()==n) {
        v.push_back(s);
        return;
    }

    helper(n, s+"0", v);

    if(s.empty() || s.back() != '1') {
        helper(n, s+"1", v);
    }
}

vector<string> genAllBinStr(int n) {
    string s="";
    vector<string> v;

    helper(n, s, v);

    return v;
}

int main() {
    int n;
    cin>>n;

    vector<string> ans = genAllBinStr(n);
    for(const auto x: ans) {
        cout<<x<<" ";
    }

    return 0;
}