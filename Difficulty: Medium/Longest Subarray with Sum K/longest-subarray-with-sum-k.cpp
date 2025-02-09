//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int max_cnt = 0;
        int crnt_sum = 0;
        map<int, int> preSumMap;
        
        for(int i=0; i < n; i++) {
            crnt_sum+=arr[i];
            if(crnt_sum == k) max_cnt = max(max_cnt, i+1);
            else if(preSumMap.find(crnt_sum - k) != preSumMap.end()) {
                int cnt = i - preSumMap[crnt_sum-k];
                max_cnt = max(max_cnt, cnt);
            }
            if(preSumMap.find(crnt_sum) == preSumMap.end()) preSumMap[crnt_sum] = i;
        }
        
        return max_cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends