#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void setZero(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j]==0) {

                //mark row as -1 except 0s
                for(int col=0; col<n; col++) {
                    if(matrix[i][col] != 0) {
                        matrix[i][col] = -1;
                    }
                }

                //mark col as -1
                for(int row=0; row<m; row++) {
                    if(matrix[row][j] != 0) {
                        matrix[row][j] = -1;
                    }
                }
            }
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void setZeros(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            
            if(matrix[i][j]==0) {
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(row[i]==1 || col[j]==1) {
                matrix[i][j]=0;
            }
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    bool firstRowZero=false;
    bool firstColZero=false;

    //check if first row has 0
    for(int j=0; j<n; j++) {
        if(matrix[0][j]==0) {
            firstRowZero=true;
            break;
        }
    }

    //check if first col has 0
    for(int i=0; i<m; i++) {
        if(matrix[i][0]==0) {
            firstColZero=true;
            break;
        }
    }

    //mark 0s
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(matrix[i][j]==0) {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    //set 0s
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(matrix[i][0]==0 || matrix[0][j]==0) {
                matrix[i][j]=0;
            }
        }
    }

    //handle first row
    if(firstRowZero) {
        for(int j=0; j<n; j++) {
            matrix[0][j]=0;
        }
    }

    //hanle first col
    if(firstColZero) {
        for(int i=0; i<m; i++) {
            matrix[i][0]=0;
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main() {

    int m,n;
    cout<<"rows: ";
    cin>>m;
    cout<<"columns: ";
    cin>>n;

    vector<vector<int>> mt(m, vector<int>(n));

    // //or
    // vector<vector<int>> mt;
    // mt = vector<vector<int>>(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> mt[i][j];
        } 
    }

    cout<<"Matrix is: "<<endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << mt[i][j]<<" ";
        }
        cout<<endl;
    }

    // for (auto &row : mt) {
    //     for (auto &x : row) 
    //         cout << x << " ";
    //     cout << "\n";
    // }
    cout<<endl;

    cout<<"set zero is:"<<endl;
    setZero(mt);

    cout<<"set zeros is:"<<endl;
    setZeros(mt);

    cout<<"set zeroes is:"<<endl;
    setZeroes(mt);

    return 0;
}