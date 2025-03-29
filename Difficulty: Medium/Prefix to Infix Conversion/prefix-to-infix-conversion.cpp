//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
        string prev_top;
        int n = pre_exp.size();
        
        for(int i=n-1; i>=0; i--) {
            if(isalpha(pre_exp[i])) {
                if(!st.empty()) prev_top = st.top();
                st.push(string(1, pre_exp[i]));
            }
            
            else {
                string s = '(' + st.top() + pre_exp[i] + prev_top + ')';
                st.pop();
                st.pop();
                if(!st.empty()) prev_top = st.top();
                st.push(s);
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends