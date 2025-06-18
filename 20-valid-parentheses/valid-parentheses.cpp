class Solution {
public:
    bool isValid(string s) {
        // TC --> O(n)
        // SC --> O(n)
        if(s.size()&1) return false;
        stack<char> char_stk;
        for(int i=0; i < s.size(); i++) {
            if(s[i] == '(') char_stk.push(')');
            else if(s[i] == '{') char_stk.push('}');
            else if(s[i] == '[') char_stk.push(']');
            else if(!char_stk.empty() && s[i] == char_stk.top()) char_stk.pop();
            else return false;
        }
        
        return char_stk.empty() ? true : false;
    }
};