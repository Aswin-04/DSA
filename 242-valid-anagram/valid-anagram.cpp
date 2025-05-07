class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> freq(26);

        for(char ch: s) {
            freq[ch-'a']++;
        }

        for(char ch: t) {
            freq[ch-'a']--;
        }

        for(int i: freq) {
            if(i != 0) return false;
        }

        return true;
    }

    // TC --> O(N)   &&    SC --> O(26)
};