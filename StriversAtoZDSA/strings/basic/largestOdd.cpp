#include<iostream>
#include<string>
using namespace std;

string largestOdd(string s) {
    int start=0;
    int end=-1;

    for(int i=s.size()-1; i>=0; i--) {
        if((s[i]-'0')%2==1) {
            end=i;
            break;
        }
    }

    if(end==-1) {
        return "";
    }

    while(start<s.size() && s[start]=='0') {
        start++;
    }

    return s.substr(start, end-start+1);
}

int main() {
    string s;
    getline(cin, s);

    cout<<largestOdd(s)<<endl;

    return 0;
}