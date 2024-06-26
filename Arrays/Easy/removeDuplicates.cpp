#include<bits/stdc++.h>
using namespace std;

// To remove duplicates from a sorted array

// Brute force appraoch
// TC --> O(n log n + n)
// SC --> O(n) where n is the size of the set

int removeDuplicates_1(int arr[], int n) {

    set<int> st;
    for(int i=0; i < n; i++) {
        st.insert(arr[i]);
    }

    int index = 0;
    for(auto it: st) {
        arr[index++] = it;
    }
    return index;
}

// Optimal approach
// TC --> O(N)
// SC --> O(1)

int removeDuplicates_2(int arr[], int n) {

    int i = 0;
    for(int j=1; j < n; j++) {
        if(arr[i] != arr[j]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main() {

    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int num_1 = removeDuplicates_1(arr, n);
    int num_2 = removeDuplicates_2(arr, n);

    for(int i=0; i < num_2; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
