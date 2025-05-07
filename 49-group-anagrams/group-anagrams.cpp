class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted_strs;
        for(string s: strs) {
            sort(s.begin(), s.end());
            sorted_strs.push_back(s);
        }

        map<string, int> sorted_freq;
        int i=1;
        for(string s: sorted_strs) {
            if(sorted_freq.find(s) == sorted_freq.end()) sorted_freq[s] = i++;
        }

        map<int, vector<string>> strs_arr;
        for(int i=0; i < strs.size(); i++) {
            strs_arr[sorted_freq[sorted_strs[i]]].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto p: strs_arr) {
            res.push_back(p.second);
        }

        return res;


    }
};