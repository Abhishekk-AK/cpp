#include<iostream>
#include<vector>
using namespace std;

int stockBuySell(vector<int> arr, int n){
    //mini=mini price till now
    int mini=INT_MAX;
    int maxProfit=0;

    for(int i=0; i<n; i++) {
        if(mini > arr[i]) {
            mini = arr[i];
        }

        //today price - mini
        int profit = arr[i]-mini;
        maxProfit = max(profit, maxProfit);
    }
    return maxProfit;
}

int main() {

    int n;
    cin>>n;
    cout<<endl;

    vector<int> v;

    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        v.push_back(x);
    }

    cout<<"Sequence is: ";
    for(auto x: v) {
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<stockBuySell(v, v.size());

    return 0;
}