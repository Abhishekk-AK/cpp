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

int sizeLL(Node* head) {
    int s=0;
    Node* curr=head;

    while(curr) {
        s++;
        curr=curr->next;
    }
    return s;
}

Node* rotateLL(Node* head, int k) {
    
    int size = sizeLL(head);
    k=k%size;

    if(!head || !head->next || k==0) {
        return head;
    }

    int count=1;
    Node* curr=head;
    Node* prev=nullptr;
    Node* newHead=nullptr;
    
    while(curr) {
        
        if(count==size-k) {
            prev=curr;
            newHead = curr->next;
        }

        if(curr->next == nullptr) {
            curr->next = head;
            break;
        }

        curr = curr->next;
        count++;
    }

    prev->next = nullptr;

    return newHead;
}

Node* rotateLL1(Node* head, int k) {

    int size = sizeLL(head);
    k = k%size;

    if(!head || !head->next || k == 0) return head;

    int count=1;
    Node* curr=head;
    Node* split=nullptr;
    Node* newHead=nullptr;

    while(curr->next) {

        if(count == size-k) {
            split=curr;
            newHead=curr->next;
        }

        curr=curr->next;
        count++;
    }

    curr->next = head;
    split->next = nullptr;

    return newHead;
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

    int k;
    cin>>k;
    head = rotateLL(head, k);
    printList(head);

    head = rotateLL1(head, k);
    printList(head);

    return 0;
}
