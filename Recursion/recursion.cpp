#include<bits/stdc++.h>
using namespace std;

void printMyName(int i, int n) {
    if(i > n) return;
    cout << "Aswin" << endl;
    printMyName(i+1, n);
}

void print1(int i, int n) {
    if(i > n) return;
    cout << i << endl;
    print1(i+1, n);
}

void print2(int n) {
    if(n == 0) return;
    cout << n << endl;
    print2(n-1);
}

void print3(int n) {
    if(n == 0) return;
    print3(n-1);
    cout << n << endl;
}

void print4(int i, int n) {
    if(i > n) return;
    print4(i+1, n);
    cout << i << endl;
}

void printSum(int i, int sum) {
    
    if(i < 0) {
        cout << sum << endl;
        return;
    }
    printSum(i-1, sum+i);
}

int returnSum(int n) {
    if(n ==  0) return 0;
    return n + returnSum(n-1);
}

void printFactorial(int n, int fact) {
    if(n == 0) {
        cout << fact << endl;
        return;
    }
    printFactorial(n-1, fact*n);
}

int returnFactorial(int n) {
    if(n == 0) return 1;
    return n * returnFactorial(n-1);
}

void reverseArray1(int l, int r, int arr[]) {
    if(l >= r) return;
    swap(arr[l], arr[r]);
    reverseArray1(l+1, r-1, arr);
}

void reverseArray2(int i, int n, int arr[]) {
    if(i >= n/2) return;
    swap(arr[i], arr[n-i]);
    reverseArray2(i+1, n, arr);
}


int main() {

    // print my name using recursion
    printMyName(1, 5);

    // print linearly from 1 to n
    print1(1, 5);

    // print from n to 1
    print2(5);

    // print from 1 to n using back-tracking
    print3(5);

    // print from n to 1 using back-tracking
    print4(1, 5);

    // print the sum of first n numbers

    // parameterized way
    printSum(5, 0);

    // functional way
    cout << returnSum(5) << endl;

    // print factorial of n
    printFactorial(5, 1);

    // return factorial of n
    cout << returnFactorial(5) << endl;

    // reverse an array
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i < n; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    // Two pointer method
    reverseArray1(0, n-1, arr);

    // Single pointer method
    reverseArray2(0, n-1, arr);

    for(int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
