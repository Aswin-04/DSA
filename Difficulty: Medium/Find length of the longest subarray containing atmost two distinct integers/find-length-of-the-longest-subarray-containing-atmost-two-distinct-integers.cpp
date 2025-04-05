//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int, int> mp;
        int l=0;
        int n=arr.size();
        int maxLen = 0;
        
        for(int r=0; l <= r && r < n; r++) {
            mp[arr[r]]++;
            while(mp.size() > 2) {
                mp[arr[l]]--;
                if(mp[arr[l]] == 0) {
                    mp.erase(arr[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends