class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int> , vector<string>> mpp;
        for(string s: strs) {
            vector<int> count(26);
            for(char ch: s) {
                count[ch-'a']++;
            }
            mpp[count].push_back(s);
        }

        vector<vector<string>> res;
        for(auto p: mpp) {
            res.push_back(p.second);
        }

        return res;


    }
};