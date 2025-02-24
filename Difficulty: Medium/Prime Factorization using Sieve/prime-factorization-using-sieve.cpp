//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    static const int SIZE = 2*(1e5);
    vector<int> prime;
    
    Solution(): prime(SIZE+1) {
        sieve();
    }
    
    void sieve() {
        for(int i=2; i <= SIZE; i++) prime[i]=i;
        for(int i=2; i*i <= SIZE; i++) {
            if(prime[i] != i) continue;
            for(int j=i*i; j <= SIZE; j+=i) {
                if(prime[j] == j) prime[j] = i;
            }
        }
    }

    vector<int> findPrimeFactors(int N) {

        vector<int> ans;
        while(N != 1) {
            ans.push_back(prime[N]);
            N/=prime[N];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends