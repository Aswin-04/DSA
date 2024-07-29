#include<bits/stdc++.h>
using namespace std;

// Optimal Solution
// Dutch National Flag Algorithm
// TC --> O(N)

void sortColors1(vector<int> &nums) {

    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high) {

        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }

        else if(nums[mid] == 1) mid++;

        else if(nums[mid] == 2) {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// Better Solution
// TC --> O(2N)

void sortColors2(vector<int> &nums) {

    int n = nums.size();
    int cnt0 = 0;
    int cnt1 = 0;

    for(int i=0; i < n; i++) {
        if(nums[i] == 0) cnt0++;
        else if(nums[i] == 1) cnt1++;
    }

    for(int i=0; i < cnt0; i++) {
        nums[i] = 0;
    }

    for(int i = cnt0; i < cnt0+cnt1; i++) {
        nums[i] = 1;
    }

    for(int i = cnt0+cnt1; i < n; i++) {
        nums[i] = 2;
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    sortColors1(arr);
    
    for(auto it: arr) {
        cout << it << " ";
    }

    return 0;
}
