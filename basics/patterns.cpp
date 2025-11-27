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

    int n=5;

    //pattern7 -> standard centered pyramid
    for(int i=1; i<=n; i++) {
        for(int j=0; j<n-i; j++) {
            cout<<" ";
        }
        for(int k=0; k<2*i-1; k++) {
            cout<<"*";
        }
        cout<<endl;
    }

    //pattern8 -> inverse centered pyramid
    for(int i=n; i>=1; i--) {
        for(int j=0; j<n-i; j++) {
            cout<<" ";
        }
        for(int k=0; k<2*i-1; k++) {
            cout<<"*";
        }
        cout<<endl;
    }

    //pattern9 -> standard diamond
    {
        for(int i=1; i<=n; i++) {
            for(int j=0; j<n-i; j++) {
                cout<<" ";
            }
            for(int k=0; k<2*i-1; k++) {
                cout<<"*";
            }
            cout<<endl;
        }

        for(int i=n-1; i>=1; i--) {
            for(int j=0; j<n-i; j++) {
                cout<<" ";
            }
            for(int k=0; k<2*i-1; k++) {
                cout<<"*";
            }
            cout<<endl;
        }   
    }

    //left-aligned diamond
    {
        //method-1
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                cout<<"*";
            }
            cout<<endl;
        }

        for(int i=n-1; i>=1; i--) {
            for(int j=0; j<i; j++) {
                cout<<"*";
            }
            cout<<endl;
        } 

        //method-2
        int rows = 2*n-1;
        for(int i=1; i<=rows; i++) {

            int stars = (i <= n) ? i : (rows - i + 1);

            for(int j=1; j<=stars; j++) {
                cout<<"*";
            }
            cout<<endl;
        }
    }
    return 0;
}