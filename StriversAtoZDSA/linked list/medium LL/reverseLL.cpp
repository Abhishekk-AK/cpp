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
    //brute force using stack
    Node* reverseLL(Node* &head) {
        stack<int> st;
        Node* curr=head;

        while( curr ) {
            st.push(curr->data);
            curr=curr->next;
        }

        curr=head;
        while (!st.empty())
        {
            curr->data=st.top();
            curr=curr->next;
            st.pop();
        }

        return head;
    }

    //brute force using vector
    Node* reverseLL1(Node* &head) {
        vector<int> v;
        Node* curr=head;

        while( curr ) {
            v.push_back(curr->data);
            curr=curr->next;
        }


        curr=head;
        while (!v.empty())
        {
            curr->data=v.back();
            curr=curr->next;
            v.pop_back();
        }

        return head;
    }

    //optimal
    void reverseLLOpt(Node* &head) {
        Node* curr=head;
        Node* prev=nullptr;

        while(curr != nullptr) {
            Node* front=curr->next;
            curr->next=prev;

            prev=curr;
            curr=front;
        }
        head=prev;
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

    Node* head=nullptr;

    head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* fourth=new Node(4);
    Node* fifth=new Node(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    printList(head);

    obj.reverseLL(head);
    printList(head);

    obj.reverseLL1(head);
    printList(head);

    obj.reverseLLOpt(head);
    printList(head);

    return 0;
}
