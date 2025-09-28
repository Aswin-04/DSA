class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26, 0);
        for(char ch: s) {
            freq[ch-'a']++;
        }

        map<int, string> mpp;
        for(int i=0; i < 26; i++) {
            if(freq[i] == 0) continue;
            mpp[freq[i]].push_back(static_cast<char>('a'+i));
        }

        int mx = 0;
        int key = -1;
        for(auto it: mpp) {
            if(it.second.size() >= mx) {
                mx = it.second.size();
                key = it.first;
            }
        }

        return mpp[key];
    }
};