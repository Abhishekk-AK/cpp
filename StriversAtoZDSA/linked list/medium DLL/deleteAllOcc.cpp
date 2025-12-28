#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};


Node* deleteAllOccur(Node* head, int k) {

    Node* curr = head;

    while(curr != nullptr) {
        
        if(curr->data == k) {

            if(curr == head) {
                head=curr->next;
            }

            Node* nextNode = curr->next;
            Node* prevNode = curr->prev;

            if(prevNode) {
                prevNode->next = nextNode;
            }
            if(nextNode) {
                nextNode->prev = prevNode;
            }
        
            delete curr;
            curr=nextNode;         
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
}

int main() {

    int n;
    cin>>n;

    Node* head=nullptr;
    Node* tail=nullptr;

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;

        Node* newNode = new Node(x);

        if( !head ) {
            head=tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printList(head);
    cout<<endl;

    head = deleteAllOccur(head, 4);
    printList(head);

    return 0;
}