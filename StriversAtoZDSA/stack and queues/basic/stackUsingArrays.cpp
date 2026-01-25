#include<bits/stdc++.h>
using namespace std;

class ArrayStack {
    int *arr;
    int capacity;
    int top;

public:
    ArrayStack(int size) {
        capacity=size;
        arr=new int[capacity];
        top=-1;
    }
    
    void push(int x) {
        if(top>=capacity-1) return;
        top=top+1;
        arr[top]=x;
    }
    
    int pop() {
        if(top==-1) return -1;

        return arr[top--];
    }
    
    int topElement() {
        if(top==-1) return -1;

        return arr[top];
    }
    
    bool isEmpty() {
        return top==-1;
    }

    bool isFull() {
        return top==capacity-1;
    }
};