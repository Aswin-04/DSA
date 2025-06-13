class Solution {
  public:
  
    int to_int(string s) {
        int res = 0;
        for(int i=0; i < s.size(); i++) {
            res = res*10+(s[i]-'0');
        }
        return res;
    }
    
    string encode(vector<string>& s) {
        // code here
        string encoded_str = "";
        for(string str: s) {
            encoded_str += to_string(str.size()) + "#" + str;
        }
        
        return encoded_str;
    }

    vector<string> decode(string& s) {
        // code here
        
        int i=0;
        int n = s.size();
        vector<string> decoded_str;
        
        while(i < n) {
            string len_str = "";
            while(i < n && s[i] != '#') {
                len_str+=s[i];
                i++;
            }
            
            i++;
            int len = to_int(len_str);
            decoded_str.push_back(s.substr(i, len));
            i+=len;
        }
        
        return decoded_str;
    }
};