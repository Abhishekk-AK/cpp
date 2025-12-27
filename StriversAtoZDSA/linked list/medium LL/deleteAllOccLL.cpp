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

Node* deleteAllOcc(Node* head, int k) {
    if(!head) {
        return head;
    }

    while(head && head->data == k) {
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    Node* curr = head;
    //curr act as prev as head will not be equal to key anymore

    while(curr != nullptr && curr->next != nullptr) {
        
        if(curr->next->data == k) {
            Node* temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else {
            curr=curr->next;
        }
    }
    
    return head;
}

void printList(Node* head) {
    while(head != nullptr) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {

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

    head = deleteAllOcc(head, 4);
    printList(head);

    return 0;
}
