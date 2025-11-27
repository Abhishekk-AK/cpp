#include<iostream>
using namespace std;

int main(){
    //pattern1
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cout<<"*"; 
        }
        cout<<endl;
    }

    //pattern2
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=i; j++) {
            cout<<"*";
        }
        cout<<endl;
    }

    //pattern3
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=i; j++) {
            cout<<j;
        }
        cout<<endl;
    }

    //pattern4
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=i; j++) {
            cout<<i;
        }
        cout<<endl;
    }

    //pattern5
    for(int i=5; i>=1; i--) {
        for(int j=1; j<=i; j++) {
            cout<<"*";
        }
        cout<<endl;
    }

    //pattern6
    for(int i=5; i>=1; i--) {
        for(int j=1; j<=i; j++) {
            cout<<j;
        }
        cout<<endl;
    }

    return 0;
}