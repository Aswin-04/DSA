#include<bits/stdc++.h>
using namespace std;

void leftRotateArrayBynPlace(int arr[], int n, int d) {

    reverse(arr, arr+d);   // O(d)
    reverse(arr+d, arr+n); // O(n-d)
    reverse(arr, arr+n);   // O(n)

    // TC --> O(2n) 
    // SC --> O(1) since there is no extra space is used
}

int main() {
    int n;
    cin >> n;

    int d;
    cin >> d;
    d = d%n;

    int arr[n];
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    } 

    leftRotateArrayBynPlace(arr, n, d);

    for(int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
