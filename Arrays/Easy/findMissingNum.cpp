#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int xor1 = 0;
    int xor2 = 0;


    for(int i=0; i < n; i++) {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ i+1;
    }

    xor1 = xor1 ^ n+1;

    cout << (xor1 ^ xor2);

    
    return 0;
}
