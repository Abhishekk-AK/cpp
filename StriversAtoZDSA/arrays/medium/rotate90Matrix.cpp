#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//square matrix
void rotateMat(vector<vector<int>>& matrix) {
    int n=matrix.size();

    vector<vector<int>> rotated(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            rotated[j][n-i-1] = matrix[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<rotated[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotateMatrix(vector<vector<int>>& matrix) {
    int n=matrix.size();

    //transpose
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for(int i=0; i<n; i++) {
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
    cout<<endl;

    cout<<"rotate mat is:"<<endl;
    rotateMat(mt);

    cout<<"rotate matrix is:"<<endl;
    rotateMatrix(mt);

    return 0;
}