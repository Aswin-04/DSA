class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        stack<char> st;
        
        for(char ch: num) {  // O(N)
            while(!st.empty() && k>0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
            if(st.size() == 1 && ch == '0') st.pop();
        }

        while(k > 0 && !st.empty()) {  // O(N)
            st.pop();        
            k--;
        }

        string ans = "";
        while(!st.empty()) {  // O(N)
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());  // O(N)
        if(ans.size() == 0) return "0";
        return ans;

        // TC --> O(4N)  & SC --> O(N)
    }
};