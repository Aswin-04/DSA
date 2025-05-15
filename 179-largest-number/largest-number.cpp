class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for(int val: nums) {
            vs.push_back(to_string(val));
        }

        sort(vs.begin(), vs.end(), [](const string& s1, const string &s2) {
            return s1+s2 > s2+s1;
        });

        if(vs[0] == "0") return "0";
        string res = "";
        for(string num: vs) {
            res+=num;
        }

        return res;

    }
};