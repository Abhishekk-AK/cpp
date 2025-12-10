#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    int top=0;
    int left=0;
    int right=n-1;
    int bottom=m-1;
    vector<int> ans;

    while(left<=right && top<=bottom) {
        for(int i=left; i<=right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i=top; i<=bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top<=bottom) {
            for(int i=right; i>=left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left<=right) {
            for(int i=bottom; i>=top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }  
    }

    return ans;
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

    cout<<"spiral order is:"<<endl;
    vector<int> ans = spiralOrder(mt);
    for(auto x: ans) {
        cout<<x<<" ";
    }

    return 0;
}