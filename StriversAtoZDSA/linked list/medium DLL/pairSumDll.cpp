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


vector<vector<int>> findPairsWithGivenSum(Node* head, int target) {
    if(!head) return {};
    vector<vector<int>> ans;
    // if(!head) return ans;

    Node* first=head;
    Node* second=head;

    while(second->next != nullptr) {
        second=second->next;
    }

    while(first->data < second->data) {
        int sum = first->data+second->data;

        if(sum < target) {
            first=first->next;
        }
        else if(sum > target) {
            second=second->prev;
        }
        else {
            ans.push_back({first->data, second->data});

            first=first->next;
            second=second->prev;
        }
    }
    return ans;
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

    int k;
    cin>>k;

    vector<vector<int>> ans;
    ans = findPairsWithGivenSum(head, k);
    
    int p=ans.size();
    int q=ans[0].size();

    for(int i=0; i<p; i++) {
        for(int j=0; j<q; j++) {
            cout<<ans[i][j];
            if(j==0) {
                cout<<",";
            }
        }
        cout<<endl;
    }

    return 0;
}