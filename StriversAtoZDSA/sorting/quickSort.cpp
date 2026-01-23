#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[low];

    int i=low;
    int j=high;

    while(i<j) {
        while(nums[i] <= pivot && i <= high-1) {
            i++;
        }
        while(nums[j] > pivot && j >= low+1) {
            j--;
        }

        if(i<j)
            swap(nums[i], nums[j]);
    }

    swap(nums[low], nums[j]);

    return j;

}

void qsort(vector<int>& nums, int low, int high) {
    if(low >= high) {
        return;
    }

    int pivotIndex = partition(nums, low, high);

    qsort(nums, low, pivotIndex-1);
    qsort(nums, pivotIndex+1, high);

}

void quickSort(vector<int>& nums) {
    qsort(nums, 0, nums.size()-1);
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

    cout<<"Before sorting: ";
    for(auto x: v) {
        cout<<x<<" ";
    }
    cout<<endl;

    quickSort(v);

    cout<<"After sorting: ";
    for(auto x: v) {
        cout<<x<<" ";
    }

    return 0;
}