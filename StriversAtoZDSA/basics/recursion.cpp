#include<bits/stdc++.h>
using namespace std;

//1-n
void printNumbers(int n) {
    if(n==0)
        return;

    printNumbers(n-1);
    cout<<n<<'\n';
}

//n-1
void printNto1(int n) {
    if(n==0)
        return;
    cout<<n<<'\n';
    printNumbers(--n);
}

int NnumbersSum(int N){
    if(N==0)
        return 0;

    return N + NnumbersSum(N-1);
}

int factorial(int n) {
    if(n==0)
        return 1;
    return n * factorial(n-1);
}

//reverse the array content
void reverse(int arr[], int n) {
    static int i=0;

    if(i>=n-1)
        return;

    swap(arr[i], arr[n-1]);
    i++;

    reverse(arr, n-1);

    if(i==1) {
        for(int j=0; j<n+i; j++)
            cout<<arr[j]<<" ";
    }
}

void reverse1(int arr[], int n) {
    if(n<=1) 
        return;

    int temp=arr[0];
    arr[0]=arr[n-1];
    arr[n-1]=temp;

    reverse1(arr+1, n-2);
}

//only prints the array-> do not actually modify the array content
void reversePrint(int arr[], int n) {
    // if(n==0)
    //     return;

    if(n==1) {
        cout<<arr[0];
        return;
    }

    cout<<arr[n-1]<<" ";
    reversePrint(arr, n-1);
}

int fib(int n) {
    // if(n==0)
    //     return 0;
    // if(n==1)
    //     return 1;
    // return fib(n-1) + fib(n-2);


    // if(n<=1)
    //     return n;
    // int fib[n+1];
    // fib[0]=0;
    // fib[1]=1;

    // for(int i=2; i<=n; i++) {
    //     fib[i]=fib[i-1] + fib[i-2];
    // }
    // return fib[n];


    if (n<=1) 
        return n;

    int a=0, b=1;
    for (int i=2; i<=n; i++) {
        int c = a+b;
        a=b;
        b=c;
    }
    return b;
}

//pallindrome without any conditions
bool palindromeCheck(string& s){
    int n=s.length();

    for(int i=0; i<n/2; i++) {
        if(s[i]!=s[n-1-i])
            return false;
    }
    return true;
}

bool isPalindromeHelper(string& s, int left, int right) {
    if(left>=right)
        return true;

    if(s[left]!=s[right])
        return false;

    return isPalindromeHelper(s, left+1, right-1);
}

//pallindrome with recursion
bool palindromeRecursion(string& s) {
    return isPalindromeHelper(s, 0, s.size()-1);
}


int main() {

    printNumbers(4);
    cout<<'\n';

    printNto1(4);
    cout<<'\n';

    cout<<NnumbersSum(5);
    cout<<'\n';

    cout<<factorial(5);
    cout<<'\n';

    int arr[5] = {1,2,3,4,5};

    int arr1[5] = {1,2,3,4,5};
    reverse(arr1, 5);
    for(int x: arr1)
        cout<<x<<" ";
    cout<<"reverse"<<'\n';

    int arr2[5] = {1,2,3,4,5};
    reverse1(arr2, 5);
    for(int x: arr2)
        cout<<x<<" ";
    cout<<"reverse1"<<'\n';

    reversePrint(arr, 5);
    cout<<"reversePrint"<<'\n';

    cout<<fib(6)<<'\n';

    string s="daaabaaad";
    cout<<palindromeCheck(s)<<'\n';

    string s1="hjuih";
    cout<<palindromeRecursion(s1)<<'\n';

    return 0;
}