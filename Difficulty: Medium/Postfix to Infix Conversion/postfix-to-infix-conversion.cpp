//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        string prev_top;
        
        for(int i=0; i < exp.size(); i++) {
            if(isalnum(exp[i])) {
                if(!st.empty()) prev_top = st.top();
                st.push(string(1, exp[i]));
            }
            
            else {
                string s = '(' + prev_top + exp[i] + st.top() + ')';
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);

    return 0;
}

// } Driver Code Ends