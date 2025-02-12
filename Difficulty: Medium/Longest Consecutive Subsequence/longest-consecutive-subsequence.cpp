//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    // TC --> O ( N )
    // SC --> O ( N )
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st;
        for(int i: arr) st.insert(i);
        
        int max_cnt = 1;
        for(int it: st) {
            if(st.find(it-1) != st.end()) continue;
            int cnt = 1;
            int increment = 1;
            while(st.find(it+increment) != st.end()) {
                cnt++;
                increment++;
                max_cnt = max(max_cnt, cnt);
            }
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