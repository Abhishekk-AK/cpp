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
    Node* middleOfList(Node* head) {
        Node* slow=head;
        Node* fast=head;

        while(fast != nullptr && fast->next != nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
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
    //Node* fifth=new Node(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    //fourth->next=fifth;

    printList(head);

    //pass by ref
    cout<<obj.middleOfList(head)->data;

    return 0;
}
