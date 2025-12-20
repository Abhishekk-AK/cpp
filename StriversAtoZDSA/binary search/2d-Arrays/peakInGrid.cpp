#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> peakGrid(vector<vector<int>> & nums) {
    int n=nums.size();
    int m=nums[0].size();
    int top, right, bottom, left;
    
    for(int i=0; i<n; i++) {

        for(int j=0; j<m; j++) {

            if(i==0) top=0;
            else top=nums[i-1][j];

            if(i==n-1) bottom=0;
            else bottom=nums[i+1][j];

            if(j==0) left=0;
            else left=nums[i][j-1];

            if(j==m-1) right=0;
            else right=nums[i][j+1];


            if(nums[i][j]>top && nums[i][j]>right 
                && nums[i][j]>bottom && nums[i][j]>left)
            {
                return {i,j};
            }
        }
    
    }

    return {-1,-1};
}


int maxElement(vector<vector<int>>& nums, int col) {
    int n=nums.size();
    int maxEle=INT_MIN;
    int index=-1;

    for(int i=0; i<n; i++) {
        if(nums[i][col]>maxEle) {
            maxEle=nums[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> peakGridOpt(vector<vector<int>>& nums) {
    int n=nums.size();
    int m=nums[0].size();

    int low=0;
    int high=m-1;

    for(int i=0; i<n; i++) {
        while(low<=high) {
            int mid=low+(high-low)/2;

            int row=maxElement(nums, mid);

            if(mid>0 && (nums[row][mid]<nums[row][mid-1]) ) {
                high=mid;
            }
            else if(mid<m-1 && (nums[row][mid]<nums[row][mid+1]) ) {
                low=mid+1;
            }
            else {
                return {row,mid};
            }
        }
    }
    
    return {-1,-1};
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

    vector<int> ans = peakGrid(mt);
    for(auto x: ans) {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> ans1 = peakGridOpt(mt);
    for(auto x: ans1) {
        cout<<x<<" ";
    }

    return 0;
}