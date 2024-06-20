#include<bits/stdc++.h>
using namespace std;

// TC --> (storing , fetching) for map: O(log(n))
// TC --> (storing, fetching) for unordered_map: O(1)
// for worst case O(n), when collision occurs
// where n is the number of elements in map  

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> mpp;
    
    // precompute
    for(int i=0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    while(q--) {
        int num;
        cin >> num;
        cout << mpp[num] << endl;
    }

    return 0;
}
