class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string firstStr = strs[0];
        string lastStr = strs[strs.size()-1];

        int n = min(firstStr.size(), lastStr.size());
        string ans = "";
        for(int i=0; i < n; i++) {
            if(firstStr[i] == lastStr[i]) ans+=firstStr[i];
            else break;
        }

        return ans;
    }
};