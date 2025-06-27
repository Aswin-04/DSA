// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
        vector<int> prime(N+1, 1);
        prime[0] = 0;
        prime[1] = 0;
        
        for(int i=2; i <= N; i++) {
            if(prime[i] == 0) continue;
            for(long long j=1LL*i*i; j <= N; j+=i) {
                prime[j] = 0;
            }
        }
        
        vector<int> res;
        for(int i=M; i <= N; i++) {
            if(prime[i]) res.push_back(i);
        }
        
        return res;
    }
};