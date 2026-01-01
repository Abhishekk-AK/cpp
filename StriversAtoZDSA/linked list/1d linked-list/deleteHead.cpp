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
    Node* deleteHead(Node* &head) {
        if(head==nullptr) {
            return nullptr;
        }
    
        Node* temp=head;
        head = head->next;
        delete temp;

        return head;
    }

    Node* deleteHead1(Node* head) {
        if(head==nullptr) {
            return nullptr;
        }
        
        Node* temp = head;
        head = head->next;
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

    Node* head=nullptr;

    head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);

    printList(head);

    //pass by ref
    obj.deleteHead(head);
    printList(head);

    //pass by val
    head = obj.deleteHead1(head);
    printList(head);

    return 0;
}
