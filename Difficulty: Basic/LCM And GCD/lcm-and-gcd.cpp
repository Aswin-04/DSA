//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int get_gcd(int a, int b) {
        if(a == 0) return b;
        return get_gcd(b%a, a);
    }
    
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        int gcd = get_gcd(a, b);
        int lcm = (1LL*a*b)/gcd;
        
        return {lcm, gcd};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends