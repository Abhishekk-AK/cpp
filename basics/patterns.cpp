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

    //pattern10 left-aligned diamond
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

    //pattern11
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            int res = (i+j)%2 ? 0 : 1;
            cout<<res<<" ";
            // cout<<(1-(i+j)%2)<<" ";
            // cout<<-((i+j)%2-1)<<" ";
        }
        cout<<endl; 
    }

    //pattern12 Mirror-triangle
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<j;
        }

        for(int k=2*(n-i); k>=2; k-=2) {
            cout<<"  ";
        }

        // int spaces = 2*(n-i);
        // for(int s=0; s<spaces; s++)
        //     cout<<" ";

        // cout<<string(2*(n-i), ' ');

        for(int l=i; l>=1; l--) {
            cout<<l;
        }
        cout<<endl;
    }

    //pattern13
    int res = 1;
    for(int i=1; i<=n; i++) { 
        for (int j=1; j<=i; j++) {
            cout<<res++<<" ";
        }
        cout<<endl;
    }

    //pattern14
    for(int i=1; i<=n; i++) { 
        char res = 'A';
        for (int j=1; j<=i; j++) {
            cout<<res++<<" ";
        }
        cout<<endl;
    }

    //pattern15
    for(char i='E'; i>='A'; i--) { 
        for(char j='A'; j<=i; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    //pattern16
    for(char i='A'; i<='E'; i++) { 
        for(char j='A'; j<=i; j++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    //pattern17 Pallindromic-Alphabet pyramid
    for(int i=0; i<n; i++) {

        for(int j=n-1; j>=i; j--) {
            cout<<" ";
        }
        for(int j=0; j<=i; j++) {
            cout<<char('A' + j);
        }
        for(int j=i-1; j>=0; j--) {
            cout<<char('A' + j);
        }
        cout<<'\n';
    }

    //pattern18 Inverted-Alphabet-Triangle
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {

            int res = i-j;
            char ch = 'A' + (n-1);
            cout<<char(ch - res)<<" ";
        }
        cout<<'\n';
    }

    //pattern19 Double-mirrored-hourglass
    for(int i=1; i<=2*n; i++) {

        int stars = (i<=n) ? (n-i+1) : (i-n);
        for(int j=1; j<=stars; j++) {
                cout<<"*";
        }

        //int spaces = (i<=n) ? 2*(i-1) : 2*(2*n-i);
        int spaces = 2*(n-stars);
        for(int j=0; j<spaces; j++) {
            cout<<" ";
        }

        for(int j=1; j<=stars; j++) {
                cout<<"*";
        }
        cout<<'\n';
    }

    //pattern20 Mirrored-butterfly
    for(int i=1; i<2*n; i++) {

        int stars = (i<=n) ? i : (2*n-i);
        for(int j=1; j<=stars; j++) {
            cout<<"*";
        }

        int spaces = (i<n) ? (2*n-2*i) : 2*(i-n) ;
        for(int j=spaces; j>=1; j--) {
            cout<<" ";
        }

        for(int j=1; j<=stars; j++) {
            cout<<"*";
        }

        cout<<'\n';
    }

    //pattern21 Hollow-square
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {

            cout<<((i==1 || j==1 || i==n || j==n) ? "*" : " ");

        }
        cout<<'\n';
    } 

    //pattern22
    {
        //method-1 array
        int size = 2*n-1;
        int a[100][100];

        for(int ring=0; ring<n; ring++) {
            
            int val = n-ring;
            int start = ring;
            int end = size-1-ring;


            for(int j=start; j<=end; j++) {
                a[start][j] = val;
            }

            for(int j=start; j<=end; j++) {
                a[end][j] = val;
            }
            
            for(int i=start; i<=end; i++) {
                a[i][start] = val;
            }

            for(int i=start; i<=end; i++) {
                a[i][end] = val;
            }
        }

        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
        
        //method2
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {

                int top=i;
                int left=j;
                int right=size-1-j;
                int bottom=size-1-i;

                int smallest=top;

                if(left<smallest)
                    smallest=left;
                if(right<smallest)
                    smallest=right;
                if(bottom<smallest)
                    smallest=bottom;
                
                int val=n-smallest;

                cout<<val<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';

        //method3
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {

                int val=n;

                for(int ring=0; ring<n; ring++) {

                    if(i==ring || j==ring || i==size-1-ring || j==size-1-ring) {
                        val=n-ring;
                        break;
                    }
                }
                cout<<val<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';

        //method4
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {

                int top=i;
                int left=j;
                int right=size-1-j;
                int bottom=size-1-i;

                int val = min(min(top,bottom), min(left,right));

                cout<<n-val<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';

    }

    //pattern23
    int size=2*n-1;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {

            int top=i;
            int left=j;
            int right=size-1-j;
            int bottom=size-1-i;

            int smallest=top;

            if(left<smallest)
                smallest=left;
            if(right<smallest)
                smallest=right;
            if(bottom<smallest)
                smallest=bottom;
            
            int val=n-smallest;

            cout<<smallest<<" ";
        }
        cout<<'\n';
    }
    
    return 0;
}