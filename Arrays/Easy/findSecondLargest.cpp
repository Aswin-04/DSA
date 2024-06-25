#include<bits/stdc++.h>
using namespace std;


int findSecondLargestElement_1(int arr[], int n) {

    int largest = arr[0];
    int secondLargest = INT_MIN;

    for(int i=0; i < n; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }

        else if(arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    } 

    cout << findSecondLargestElement_1(arr, n) << endl;

    return 0;
}
