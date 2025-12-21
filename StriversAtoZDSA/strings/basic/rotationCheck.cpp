#include<iostream>
#include<string>
using namespace std;

bool rotateStringCheck(string s, string goal) {
    if(s.size() != goal.size()) {
        return 0;
    }

    int n=s.size();
    s += s;

    for(int i=0; i<n; i++) {
        bool match=true;
        for(int j=0; j<n; j++) {
            if(s[i+j] != goal[j]) {
                match=false;
                break;
            }
        }
        if(match) {
            return true;
        }
    }

    return false;
}

int main() {
    string s;
    getline(cin, s);

    string goal;
    getline(cin, goal);

    cout<<rotateStringCheck(s, goal)<<endl;

    return 0;
}