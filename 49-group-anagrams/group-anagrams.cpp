class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagramHash;
        vector<vector<string>> ans;

        for(string str: strs) {
            vector<int> freq(26, 0);
            for(char ch: str) {
                freq[ch-'a']++;
            }
            anagramHash[freq].push_back(str);
        }

        for(auto pr: anagramHash) {
            ans.push_back(pr.second);
        }

        return ans;
    }
};