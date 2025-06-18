class Solution {
public:
    string minWindow(string s, string t) {

        // TC --> O(n)
        // SC --> O(n1+n1)
        if(t.size() > s.size()) return "";

        unordered_map<char, int> window, freqT;
        for(char ch: t) {
            freqT[ch]++;
        }

        int l=0;
        int r=0;
        int n = s.size();
        pair<int, int> idx = {-1, n};
        int need=t.size();
        int have=0;

        while(r < n) {
            window[s[r]]++;

            if(freqT.count(s[r]) &&
               window[s[r]] <= freqT[s[r]]) {
                have++;
            }
               
            if(have == need) {
                while(l < r) {
                    if(!freqT.count(s[l]) || window[s[l]] > freqT[s[l]]) {
                        window[s[l]]--;
                        l++;
                    } 
                    else break;
                }

                if(r-l+1 < idx.second-idx.first+1) {
                    idx.first = l;
                    idx.second = r;
                }

                window[s[l]]--;
                l++;
                have--;
            }
            
            r++;
        }

        if(idx.first == -1) return "";
        return s.substr(idx.first, idx.second-idx.first+1);
    }
};