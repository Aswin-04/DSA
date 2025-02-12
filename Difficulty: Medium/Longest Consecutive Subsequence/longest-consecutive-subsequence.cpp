//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int cnt = 1;
        int max_cnt = 1;
        
        for(int i=1; i < n; i++) {
            if(arr[i]-1 == arr[i-1]) {
                cnt++;
                max_cnt = max(max_cnt, cnt);
            }
            
            else if(arr[i] == arr[i-1]) continue;
            else cnt = 1;
        }
        
        return max_cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends