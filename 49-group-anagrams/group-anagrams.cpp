class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // TC --> O(M*N)  &   SC --> O(M) extra space and O(M*N) for output list

        unordered_map<string, vector<string>> mpp;
        for(string s: strs) {
            vector<int> count(26);
            for(char ch: s) {
                count[ch-'a']++;
            }
            
            string key = to_string(count[0]);
            for(int i=1; i < 26; i++) {
                key+=','+to_string(count[i]);
            }
            mpp[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto p: mpp) {
            res.push_back(p.second);
        }

        return res;
    }
};