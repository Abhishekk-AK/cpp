#include<bits/stdc++.h>
using namespace std;


//TC O(sqrt(n) * log(n))
vector<int> primeFactors2(int n) {
    vector<int> ans;

    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            while(n%i==0) {
                ans.push_back(i);
                n/=i;
            }
        }
    }
    if(n!=1) ans.push_back(n);
    
    return ans;
}


vector<vector<int>> primeFactorsArray(vector<int>& queries) {
    vector<vector<int>> res;

    for(int i=0; i<queries.size(); i++) {
        res.push_back(primeFactors2(queries[i]));
    }
    return res;
}

int main() {
    int m;
    vector<int> queries;

    while(cin>>m) {
        queries.push_back(m);
    }

    vector<vector<int>> res = primeFactorsArray(queries);
    for(auto x: res) {
        for(auto y: x) {
            cout<<y<<" ";
        }
    }

    //formatting
    cout<<endl;
    cout<<"[";
    bool firstVec=true;

    for(auto x: res) {
        if(!firstVec) cout<<", ";
        firstVec=false;

        cout<<"[";
        bool firstEle=true;

        for(auto y: x) {
            if(!firstEle) cout<<", ";
            firstEle=false;

            cout<<y;
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
}