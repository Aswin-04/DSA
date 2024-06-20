#include<bits/stdc++.h>
using namespace std;

int returnFibonacci(int num) {

    if(num <= 1) return num;
    return returnFibonacci(num-2) + returnFibonacci(num-1);
}

int main() {

    int num;
    cin >> num;

    cout << returnFibonacci(num);

    return 0;
}
