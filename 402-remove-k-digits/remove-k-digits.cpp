class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        stack<char> st;
        
        for(char ch: num) {
            while(!st.empty() && k>0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k > 0 && !st.empty()) {
            st.pop();        
            k--;
        }

        string ans = "";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        int start=0;
        while(start < ans.size() && ans[start] == '0') start++;
        if(start == ans.size()) return "0";
        return ans.substr(start);
    }
};