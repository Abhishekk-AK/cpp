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

int main() {

    Node* head;


    head=new Node(1);

    head->next=new Node(2);
    head->next->prev=head;

    head->next->next=new Node(3);
    head->next->next->prev=head->next;

    // Node* head = new Node(1);
    // Node* second = new Node(2);
    // Node* third = new Node(3);

    // // Connect next pointers
    // head->next = second;
    // second->next = third;

    // // Connect prev pointers
    // second->prev = head;
    // third->prev = second;

    // Node* y = second;


    Node* y=head->next;

    cout << y->prev << '\n';
    cout << y->next << '\n';

    cout << y->data << '\n';

    return 0;
}
