class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string encoded_str = "";
        for(int i=0; i < s.size(); i++) {
            encoded_str+=(to_string(s[i].size()) + "#" + s[i]);
        }
        
        return encoded_str;
        
    }

    vector<string> decode(string& s) {
        // code here
        int i=0;
        int n = s.size();
        vector<string> res;
        
        while(i < n) {
            string cnt_str = "";
            while(s[i] != '#') {
                cnt_str+=s[i];
                i++;
            }
            
            i++;
            int char_count = stoi(cnt_str);
            res.push_back(s.substr(i, char_count));
            i+=char_count;
        }
        
        return res;
        
    }
};