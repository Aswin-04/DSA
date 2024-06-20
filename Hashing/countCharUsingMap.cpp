#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    char arr[n];

    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    map<char, int> mpp;
    
    // precompute
    for(int i=0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    while(q--) {
        char ch;
        cin >> ch;
        cout << mpp[ch] << endl;
    }
    
    return 0;
}
