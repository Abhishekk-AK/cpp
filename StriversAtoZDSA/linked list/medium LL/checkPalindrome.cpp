#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;  

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution {
    public:
    //brute
    bool isPalindrome(Node* head) {
        if(!head || !head->next) {
            return head;
        }

        stack<int> st;
        Node* curr=head;

        while(curr != nullptr) {
            st.push(curr->data);
            curr = curr->next;
        }

        curr=head;

        while(!st.empty()) {
            if(st.top() == curr->data) {
                curr = curr->next;
                st.pop();
            }
            else {
                return false;
            }
        }
        
        return true;
    }

    //optimal
    bool isPalindromeOPt(Node* head) {
        if(!head || !head->next) {
            return true;
        }

        Node* slow=head;
        Node* fast=head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newHead = reverseLL(slow->next);
        Node* first = head;
        Node* second = newHead;

        while(second != nullptr) {

            if(first->data != second->data) {
                reverseLL(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverseLL(newHead);
        return true;
    }

    Node* reverseLL(Node* head) {
        Node* curr=head;
        Node* prev=nullptr;

        while(curr) {
            Node* front=curr->next;

            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
};

void printList(Node* head) {
    while(head != nullptr) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    Solution obj;

    int n;
    cin>>n;

    Node* head=nullptr;
    Node* tail=nullptr;

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;

        Node* newNode=new Node(x);

        if(head==nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next=newNode;
            tail=newNode;
        }
    }

    printList(head);

    //create loop then detect loop

    cout<<obj.isPalindrome(head)<<endl;

    cout<<obj.isPalindromeOPt(head)<<endl;

    return 0;
}
