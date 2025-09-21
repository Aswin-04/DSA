class Solution {
public:
    int getLeastFrequentDigit(int n) {
        
        vector<int> freq(10, 0);
        while(n) {
            int ld = n%10;
            freq[ld]++;
            n/=10;
        }

        int res = INT_MAX;
        int ans = -1;
        for(int i=0; i < freq.size(); i++) {
            if(freq[i] == 0) continue;
            if(freq[i] < res) {
                res = freq[i];
                ans = i;
            }
            if(freq[i] == res) {
                if(i < ans) ans = i;
            } 
        }

        return ans;
    }
};