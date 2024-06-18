#include<bits/stdc++.h>
using namespace std;

// To get the count of a given num in a array, where the max num is 14

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // precompute

    int hash[14] = {0};
    for(int i=0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--) {
        int num;
        cin >> num;
        cout << hash[num] << endl;
    }

    
    
    return 0;
}
