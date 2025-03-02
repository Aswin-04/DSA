class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int, int> freq1;
        map<int, int> freq2;

        if(s.size() != t.size()) return false;
        for(int i=0; i < s.size(); i++) {
            freq1[s[i]]++;
            freq2[t[i]]++;
        }

        for(auto it: freq1) {
            if(freq2.find(it.first) == freq2.end()) return false;
            if(freq2[it.first] != it.second) return false;
        }

        return true;
    }
};