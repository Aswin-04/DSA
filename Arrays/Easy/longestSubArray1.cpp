#include<bits/stdc++.h>
using namespace std;

int getLongestSubArray_1(int arr[], int n, int k) {
    
    int maxLen = 0;
    long long sum = 0;
    map<long long, int> mpp;

    for(int i=0; i < n; i++) {
        sum+=arr[i];

        if(sum == k) {
            maxLen = i+1;
        }

        long long rem = sum - k;

        if(mpp.find(rem) != mpp.end()) {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);  

        }

        if(mpp.find(sum) == mpp.end()) {
            mpp[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << getLongestSubArray_1(arr, n, k);

    return 0;
}
