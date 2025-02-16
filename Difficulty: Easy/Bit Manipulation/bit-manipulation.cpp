//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void get(int num, int i) {
        if((num & (1 << (i-1))) > 0) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    
    void set(int &num, int i) {
        num = num | (1 << (i-1));
        cout << num << ' ';
    }
    
    void clear(int &num, int i) {
        num = num & (~(1 << (i-1)));
        cout << num << ' ';
    }
    
    void bitManipulation(int num, int i) {
        // your code here
        get(num, i);
        set(num, i);
        clear(num, i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends