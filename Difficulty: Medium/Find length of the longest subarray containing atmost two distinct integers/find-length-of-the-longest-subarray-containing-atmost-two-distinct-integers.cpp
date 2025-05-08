//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int, int> mpp;
        int i=0;
        int j=0;
        int maxLen = 0;
        while(j < arr.size()) {
            mpp[arr[j]]++;
            
            while(mpp.size() > 2) {
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0) mpp.erase(arr[i]);
                i++;
            }
            
            maxLen = max(maxLen, j-i+1);
            j++;
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