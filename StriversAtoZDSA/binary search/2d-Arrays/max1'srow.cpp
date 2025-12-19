#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int max1sRow(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    int maxCount=0;
    int maxRow=-1;

    for(int i=0; i<m; i++) {
        int count=0;
        for(int j=0; j<n; j++) {
            if(matrix[i][j]==1) {
                count++;
            }
        }
        
        if(count>maxCount) {
            maxCount=count;
            maxRow=i;
        }
    }
    return maxRow;
}

int rowWithMax1s(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    int maxCount=0;
    int maxRow=-1;

    for(int i=0; i<m; i++) {
        int low=0; int high=n-1;

        while(low<=high) {
            int mid=low+(high-low)/2;

            if(mat[i][mid]==1) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }

        int noOf1s=n-low;

        if(noOf1s>maxCount) {
            maxCount=noOf1s;
            maxRow=i;
        }
    }
    return maxRow;
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

    cout<<max1sRow(mt)<<endl;

    cout<<rowWithMax1s(mt);

    return 0;
}