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
    int getLength(Node* head) {
        if(head==nullptr) {
            return 0;
        }
    
        Node* curr=head;
        int len=0;

        while(curr != nullptr) {
            len++;
            curr = curr->next;
        }

        return len;
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

    cout<<obj.getLength(head);

    return 0;
}
