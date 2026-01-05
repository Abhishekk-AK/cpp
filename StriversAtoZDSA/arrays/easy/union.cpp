#include<iostream>
#include<vector>
using namespace std;

// vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
//     int m=nums1.size();
//     int n=nums2.size();

//     vector<int> v;
//     int i=0, j=0;

//     while(i<m && j<n) {

//         if(nums1[i] < nums2[j]) {
//             v.push_back(nums1[i]);
//             i++;
//         }
//         else if(nums1[i] == nums2[j]) {
//             v.push_back(nums1[i]);
//             i++;
//             j++;
//         }
//         else {
//             v.push_back(nums2[j]);
//             j++;
//         }
//     }
//     while(i<m) {
//         v.push_back(nums1[i]);
//         i++;
//     }
//     while(j<n) {
//         v.push_back(nums2[j]);
//         j++;
//     }
    
//     return v;
// }


//only unique elements in union
vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size();
    int n=nums2.size();

    vector<int> v;
    int i=0, j=0;

    while(i<m && j<n) {

        if(nums1[i] < nums2[j]) {
            if(v.empty() || v.back() != nums1[i]) {
                v.push_back(nums1[i]);
            }
            i++;
        }
        else if(nums1[i] == nums2[j]) {
            if(v.empty() || v.back() != nums1[i]) {
                v.push_back(nums1[i]);
            }
            i++;
            j++;
        }
        else {
            if(v.empty() || v.back() != nums2[j]) {
                v.push_back(nums2[j]);
            }
            j++;
        }
    }
    while(i<m) {
        if(v.empty() || v.back() != nums1[i]) {
            v.push_back(nums1[i]);
        }
        i++;
    }
    while(j<n) {
        if(v.empty() || v.back() != nums2[j]) {
            v.push_back(nums2[j]);
        }
        j++;
    }
    
    return v;
}

// //using lambda function
// vector<int> uniqueUnion(vector<int>& nums1, vector<int>& nums2) {
//     int i = 0, j = 0;
//     vector<int> v;

//     auto add = [&](int x) {
//         if(v.empty() || v.back() != x)
//             v.push_back(x);
//     };

//     while (i < nums1.size() && j < nums2.size()) {
//         if (nums1[i] < nums2[j]) {
//             add(nums1[i]);
//             i++;
//         }
//         else if (nums1[i] > nums2[j]) {
//             add(nums2[j]);
//             j++;
//         }
//         else {
//             add(nums1[i]);
//             i++;
//             j++;
//         }
//     }

//     while (i < nums1.size()) 
//         add(nums1[i++]);
//     while (j < nums2.size()) 
//         add(nums2[j++]);

//     return v;
// }


int main() {

    int m;
    cin>>m;
    cout<<endl;

    vector<int> v1;

    int x;
    for(int i=0; i<m; i++) {
        cin>>x;
        v1.push_back(x);
    }

    cout<<"Sequence 1 is: ";
    for(auto x: v1) {
        cout<<x<<" ";
    }
    cout<<endl;

    int n;
    cin>>n;
    cout<<endl;

    vector<int> v2;

    int y;
    for(int i=0; i<n; i++) {
        cin>>y;
        v2.push_back(y);
    }

    cout<<"Sequence 2 is: ";
    for(auto x: v2) {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> ans = unionArray(v1, v2);
    for(auto x: ans) {
        cout<<x<<" ";
    }

    return 0;
}