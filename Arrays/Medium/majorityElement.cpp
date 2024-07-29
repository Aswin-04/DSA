#include<bits/stdc++.h>
using namespace std;

// My Solution 
// TC --> O(N + N log N)
// SC --> O(1)

int majorityElement1(vector<int> nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min = n/2;
        int cnt = 1;
        for(int i=0; i < n-1; i++) {
            if(nums[i] != nums[i+1]) {
                if(cnt > min) {
                    return nums[i];
                }
                cnt = 1;
            } 

            else cnt++;
        }
        return nums[n-1];
}

// Better Solution Using Hashing
// TC --> O(N log N) + O(N)
// SC --> O(N/2)

int majorityElement2(vector<int> nums) {

    int n = nums.size();
    map<int, int> mpp;

    for(int i=0; i < n; i++) {
        mpp[nums[i]]++;
    }

    int min = n/2;
    for(auto it: mpp) {
        if(it.second > min) return it.first;
    }

    return -1;
}

// Optimal Solution 
// Moore's Voting Algorithm
// TC --> O(N)

int majorityElement3(vector<int> nums) {

    int ele;
    int cnt = 0;

    for(int i=0; i < nums.size(); i++) {

        if(cnt == 0) {
            ele = nums[i];
            cnt = 1;
        }
        else if(ele == nums[i]) cnt++;
        else cnt--;
    }

    return ele;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    } 

    int ans = majorityElement3(arr);
    cout << ans << endl;

    
    return 0;
}
