class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets;
        brackets.insert({')', '('});
        brackets.insert({'}', '{'});
        brackets.insert({']', '['});

        stack<char> st;
        for(char ch: s) {
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if(st.empty() || st.top() != brackets[ch]) return false;
            else st.pop();
        }

        return st.empty();
    }
};