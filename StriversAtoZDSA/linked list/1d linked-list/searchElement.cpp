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
    bool searchKey(Node* head, int x) {
        if(head==nullptr) {
            return false;
        }

        while(head != nullptr) {
            if(head->data == x) {
                return true;
            }
            head = head->next;
        }

        return false;
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

    cout<<obj.searchKey(head, 3);

    return 0;
}
