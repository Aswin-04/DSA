class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>, vector<string>> anagramHash;
        for (string s : strs) {
            vector<int> freq(26, 0);
            for (char ch : s) {
                freq[ch - 'a']++;
            }
            anagramHash[freq].push_back(s);
        }

        vector<vector<string>> answer;
        for (auto pr : anagramHash) {
            answer.push_back(pr.second);
        }

        return answer;
    }
};