//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> divisors;
        for(int i=1; i*i <= n; i++) {
            if(n%i == 0) {
                divisors.push_back(i);
                if(n/i != i) {
                    divisors.push_back(n/i);
                }
            }
        }
        
        for(int i=0; i < divisors.size(); i+=2) {
            cout << divisors[i] << ' ';
        } 
        
        int m = divisors.size()-1;
        if(divisors.size()&1) m--;
        for(int i=m; i >= 1; i-=2) {
            cout << divisors[i] << ' ';
        } 
        
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends