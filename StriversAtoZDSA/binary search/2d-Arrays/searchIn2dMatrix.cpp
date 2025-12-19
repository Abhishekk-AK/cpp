#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool searchMat(vector<vector<int>>& matrix, int target) {
    int m=matrix.size();
    int n=matrix[0].size();

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j]==target) {
                return true;
            }
        }
    }
    return false;
}

int searchMatrix(vector<vector<int>>& mat, int target) {
    int m=mat.size();
    int n=mat[0].size();

    for(int i=0; i<m; i++) {
        int low=0; int high=n-1;

        while(low<=high) {
            int mid=low+(high-low)/2;

            if(mat[i][mid]==target) {
                return true;
            }
            else if(mat[i][mid]<target) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
    }
    return false;
}

bool searchMatrixOpt(vector<vector<int>>& mat, int target) {
    int m=mat.size();
    int n=mat[0].size();

    //operating on array from (0)-to-(m*n-1)
    int low=0; int high=m*n-1;

    while(low<=high) {
        int mid=low+(high-low)/2;

        int row=mid/n;
        int col=mid%n;

        if(mat[row][col]==target) {
            return true;
        }
        else if (mat[row][col]<target) {
            low=mid+1;
        }
        else {
            high=mid-1;
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

    cout<<searchMat(mt, k)<<endl;

    cout<<searchMatrix(mt, k)<<endl;

    cout<<searchMatrixOpt(mt, k);

    return 0;
}