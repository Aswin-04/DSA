#include<bits/stdc++.h>
using namespace std;

int getLongestSubArray_1(int arr[], int n, int k) {

    int left = 0;
    int right = 0;
    int maxLen = 0;
    int sum = arr[0];

    while(right < n) {

        while(left <= right && sum > k) {
            sum-=arr[left];
            left++;
        }

        if(sum == k) {
            maxLen = max(maxLen, right-left+1);
        }

        right++;
        if(right < n) sum+=arr[right];
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
