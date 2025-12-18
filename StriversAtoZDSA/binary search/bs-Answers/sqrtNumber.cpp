#include<iostream>
#include<vector>
using namespace std;

int floorSqrt(int n) {
    int low=1;
    int high=n/2;
    int ans=0;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(mid*mid<=n) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return ans;
}

int main() {
    int n;
    cin>>n;

    cout<<floorSqrt(n)<<endl;

    return 0;
}