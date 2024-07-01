#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int maxCnt =  0;

    for(int i=0; i < n; i++) {
        if(arr[i] == 1) {
            cnt++;
        } else {
            cnt = 0;
        }

        maxCnt = max(maxCnt, cnt);
    }

    cout << maxCnt;
    
    return 0;
}
