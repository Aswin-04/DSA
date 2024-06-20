#include<bits/stdc++.h>
using namespace std;

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
