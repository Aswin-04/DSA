#include<bits/stdc++.h>
using namespace std;

// TC --> O(N log N)
// SC --> O(N)

int findLargestElement_1(int arr[], int n) {

    sort(arr, arr+n);
    return arr[n-1];
}

// TC --> O(N)

int findLargestElement_2(int arr[], int n) {

    int max = arr[0];

    for(int i=0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    } 

    int largestElement_1 = findLargestElement_1(arr, n);
    cout << largestElement_1 << endl;

    int largestElement_2 = findLargestElement_2(arr, n);
    cout << largestElement_2 << endl;

    
    
    return 0;
}
