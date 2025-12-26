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
    //brute force using map
    bool detectLoop(Node* &head) {
        unordered_map<Node*, int> mp;
        Node* curr=head;

        while( curr ) {
            if(mp.find(curr) != mp.end()) {
                return true;
            }
            mp[curr]=1;
            curr=curr->next;
        }

        return false;
    }

    //optimal with Floyd's Cycle Detection
    bool detectLoopOpt(Node* &head) {
        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }
        return false;
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

    cout<<obj.detectLoop(head)<<endl;

    cout<<obj.detectLoopOpt(head)<<endl;

    return 0;
}
