//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        // test
        int cnt = 0;
        int temp = n;
        while(temp) {
            int ld = temp%10;
            if(ld != 0 && n%ld == 0) cnt++;
            temp/=10;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends