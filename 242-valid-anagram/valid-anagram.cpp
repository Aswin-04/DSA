class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        map<char, int> freq1, freq2;
        for(int i=0; i < s.size(); i++) {
            freq1[s[i]]++;
            freq2[t[i]]++;
        } 

        for(int i=0; i < s.size(); i++) {
            if(freq1[s[i]] != freq2[s[i]]) return false;
        }

        return true;
    }
};