#include<bits/stdc++.h>
using namespace std;

// Optimal Solution
// TC --> O(n log(n))
// SC --> O(n), where n is the size of the map

vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        
        for(int i=0; i < n; i++) {
            int val = target - nums[i];
            if(mpp.find(val) != mpp.end()) {
                return {mpp[val], i};
            }
            mpp[nums[i]] = i;
        } 

        return {-1, -1};
}


int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    } 

    int target;
    cin >> target;
    vector<int> ans;

    ans = twoSum(arr, target);

    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
