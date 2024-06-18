#include<bits/stdc++.h>
using namespace std;

// To get the count of a given char in a array
int main() {
    int n;
    cin >> n;

    char arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    // precompute

    int hash[256] = {0};
    for(int i=0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--) {
        char ch;
        cin >> ch;
        cout << hash[ch] << endl;
    }

    return 0;
}
