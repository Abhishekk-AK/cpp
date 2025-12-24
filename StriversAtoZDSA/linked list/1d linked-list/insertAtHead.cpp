#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;  

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution {
    public:
    Node* insertAtHead(Node* &head, int X) {
        
        Node* newNode = new Node(X);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* insertAtHead1(Node* head, int X) {
        
        Node* newNode = new Node(X);
        newNode->next = head;
        return newNode;
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
    obj.insertAtHead(head, 7);
    printList(head);

    //pass by val
    head = obj.insertAtHead1(head, 8);
    printList(head);

    return 0;
}
