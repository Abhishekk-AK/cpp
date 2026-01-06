#include<iostream>
#include<stack>
using namespace std;

//extra stack
//TC-O(n) SC-O(n)
stack<int> reverseStack(stack<int> st) {

    stack<int> temp;
    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    return temp;
}

//using recursion stack
//TC-O(n^2) SC-O(1) /SC-O(n)rec-stack only
void insertAtBottom(stack<int> &st, int ele) {

    if(st.empty()) {
        st.push(ele);
        return;
    }

    int topEle=st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topEle);
}
void reverseStackRec(stack<int> &st) {

    if(st.empty()) {
        return;
    }

    int temp=st.top();
    st.pop();

    reverseStackRec(st);
    insertAtBottom(st, temp);
}


int main() {
    stack<int> st;
 
    int n;
    cin>>n;

    while(n) {
        int k;
        cin>>k;
        st.push(k);
        n--;
    }

    stack ans = reverseStack(st);
    while(!ans.empty()) {
        cout<<ans.top();
        ans.pop();
    }

    reverseStackRec(st);
    while(!st.empty()) {
        cout<<st.top();
        st.pop();
    }
}