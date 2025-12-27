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
    Node* deleteMiddle(Node* head) {
        if(!head || !head->next) {
            delete head;
            return nullptr;
        }

        Node* slow=head;
        Node* fast=head->next;

        while(fast && fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        Node* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;

        return head;
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

    head = obj.deleteMiddle(head);
    printList(head);

    return 0;
}
