#include<iostream>
#include<string>
#include<stack>
using namespace std;

string removeOuterParentheses(string s) {
    string ans="";
    stack<char> st;

    for(char ch: s) {

        if(ch==')') {
            st.pop();
        }
        if( !st.empty() ) {
            ans += ch;
        }
        if(ch=='(') {
            st.push(ch);
        }
    }
    return ans;
}

//for only single type of brackets
string removeOuterParentheses1(string s) {
    string ans="";
    int count=0;

    for(char ch: s) {

        if(ch==')') {
            count--;
        }
        if( count>0 ) {
            ans += ch;
        }
        if(ch=='(') {
            count++;
        }
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);

    cout<<removeOuterParentheses(s)<<endl;

    cout<<removeOuterParentheses1(s)<<endl;

    return 0;
}