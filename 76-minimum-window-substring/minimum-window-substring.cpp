class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()) return "";

        unordered_map<char, int> window, freqT;
        for(char ch: t) {
            freqT[ch]++;
        }

        int l=0;
        int r=0;
        int n = s.size();
        pair<int, int> idx = {-1, n};

        while(r < n) {
            window[s[r]]++;

            if(freqT.find(s[r]) != freqT.end()) {
                bool valid = true;
                for(auto pr: freqT) {
                    if(window.find(pr.first) == window.end() ||
                        window[pr.first] < pr.second
                    ) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    while(l <= r) {
                        if(freqT.find(s[l]) == freqT.end() || 
                            window[s[l]] > freqT[s[l]]
                            ) {
                                window[s[l]]--;
                                l++;
                        } 
                        else break;
                    }

                    int crnt_len = idx.second - idx.first +1;
                    int new_len = r-l+1;

                    if(new_len < crnt_len) {
                        idx.first = l;
                        idx.second = r;
                    }
                }
            }
            r++;
        }

        if(idx.first == -1) return "";
        return s.substr(idx.first, idx.second-idx.first+1);
    }
};