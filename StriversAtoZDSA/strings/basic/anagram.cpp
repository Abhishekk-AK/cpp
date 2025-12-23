#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool anagramStrings(string s, string t) {
    if(s.size() != t.size()) {
        return 0;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

bool checkAnagrams(string s, string t) {
    if(s.size() != t.size()) {
        return 0;
    }

    int n=s.size();
    vector<int> freq(26, 0);

    for(int i=0; i<n; i++) {
        freq[s[i]]++;
        freq[t[i]]--;
    }

    for(int i=0; i<26; i++) {
        if(freq[i] != 0) {
            return false;
        }
    }

    return true;
}


int main() {
    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    cout<<anagramStrings(s, t)<<endl;
    
    cout<<checkAnagrams(s, t)<<endl;

    return 0;
}