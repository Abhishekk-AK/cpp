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
    int loopLength(Node* &head) {
        unordered_map<Node*, int> mp;
        Node* curr=head;
        int count=1;

        while( curr ) {
            if(mp.find(curr) != mp.end()) {
                int length = count-mp[curr];
                return length;
            }
            mp[curr]=count++;
            curr=curr->next;
        }

        return 0;
    }

    //optimal with Floyd's Cycle Detection
    int loopLengthOpt(Node* &head) {
        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                int count=1;
                fast = fast->next;
                
                while(fast != slow) {
                    count++;
                    fast = fast->next;
                }
                return count;
            }
        }
        return 0;
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

    cout<<obj.loopLength(head)<<endl;

    cout<<obj.loopLengthOpt(head)<<endl;

    return 0;
}
