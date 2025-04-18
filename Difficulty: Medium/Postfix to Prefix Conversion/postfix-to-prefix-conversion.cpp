//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        stack<string> st;
        string prev_top;
        
        for(int i=0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                if(!st.empty()) prev_top = st.top();
                st.push(string(1, s[i]));
            } 
            
            else {
                string ss = s[i] + prev_top + st.top();
                st.pop();
                st.pop();
                if(!st.empty()) prev_top = st.top();
                st.push(ss);
            }
        }
        
        return st.top();
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends