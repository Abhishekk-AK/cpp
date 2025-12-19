#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//linear Search
//binary Search row-wise/col-wise

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m=mat.size();
    int n=mat[0].size();

    int row=0;
    int col=n-1;

    while(row<m && col>=0) {

        if(mat[row][col]==target) {
            return true;
        }
        else if(mat[row][col]<target) {
            row++;
        }
        else {
            col--;
        }
    }

    return false;
}


int main() {

    int m,n;
    cout<<"rows: ";
    cin>>m;
    cout<<"columns: ";
    cin>>n;

    vector<vector<int>> mt(m, vector<int>(n));

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

    int k;
    cin>>k;
    cout<<endl;

    cout<<searchMatrix(mt, k);

    return 0;
}