class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;
        vector<vector<string>> ans;

        for(int i=0; i < strs.size(); i++) {
            vector<int> freq(26, 0);
            for(int j=0; j < strs[i].size(); j++) {
                freq[strs[i][j]-'a']++;
            }
            mpp[freq].push_back(strs[i]);
        }

        for(auto p: mpp) {
            ans.push_back(p.second);
        }

        return ans;


    }
};