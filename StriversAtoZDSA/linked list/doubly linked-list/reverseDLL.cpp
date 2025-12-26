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

//brute force using extra container- stack/vector
Node* reverseList(Node* head) {
    stack<int> st;
    Node* curr = head;
    while(curr != nullptr) {
        st.push(curr->data);
        curr = curr->next;
    }

    curr = head;
    while( !st.empty() ) {
        curr->data = st.top();
        curr = curr->next;
        st.pop();
    }
    
    return head;
}

//optimal
Node* reverseListOpt(Node* head) {
    if(!head || !head->next) {
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while(curr != nullptr) {
        
        prev = curr->prev;

        curr->prev = curr->next;
        curr->next = prev;

        curr = curr->prev;
    }
    
    return prev->prev;
}

void printList(Node* head) {
    while(head != nullptr) {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main() {

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Connect next pointers
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Connect prev pointers
    second->prev = head;
    third->prev = second;
    fourth->prev = third;
    fifth->prev = fourth;

    printList(head);
    cout<<endl;

    head = reverseList(head);
    printList(head);
    cout<<endl;

    head = reverseListOpt(head);
    printList(head);

    return 0;
}
