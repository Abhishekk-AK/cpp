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


int main() {

    printNumbers(4);
    cout<<'\n';

    printNto1(4);
    cout<<'\n';

    cout<<NnumbersSum(5);
    cout<<'\n';

    cout<<factorial(5);
    cout<<'\n';

    return 0;
}