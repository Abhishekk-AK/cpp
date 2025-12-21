#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommPrefix(vector<string>& s) {
    sort(s.begin(), s.end());
    string ans="";

    string first=s[0];
    string last=s[s.size()-1];

    for(int i=0; i<first.size(); i++) {
        if(first[i] != last[i]) {
            break;
        }
        ans += first[i];
    }

    return ans;
}

int main() {
    string s;
    getline(cin, s);

    vector<string> v;
    string word;
    stringstream ss(s);

    while(ss>>word) 
    {
        v.push_back(word);
    }

    // vector<string> v1;
    // string word1="";

    // for(int i=0; i<s.size(); i++) {
    //     //push the word when space is found
    //     if(s[i]==' ') {
    //         if(!word1.empty()) {
    //             v1.push_back(word1);
    //             word1="";
    //         }
    //     }
    //     else {
    //         word1 += s[i];
    //     }
    // }

    // //push the final word w/o space
    // if(!word1.empty()) {
    //     v1.push_back(word1);
    // }

    
    for(auto &x: v) {
        cout<<x<<",";
    }
    cout<<endl;
    
    cout<<longestCommPrefix(v)<<endl;

    return 0;
}