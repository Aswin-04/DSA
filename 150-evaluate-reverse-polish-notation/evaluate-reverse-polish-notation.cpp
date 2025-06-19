class Solution {
public:

    int my_stoi(string num) {
        int result = 0;
        int sign = 1;
        int i=0;

        if(num[i] == '-') {
            sign = -1;
            i++;
        }

        else if(num[i] == '+') {
            i++;
        }

        for(; i < num.size(); i++) {
            int digit = num[i] - '0';
            result = (result*10) + digit;
        }

        return sign*result;
    }
    int eval_exp(int val1, char arth_optr, int val2) {
        switch(arth_optr) {
            case '+':
                return val1 + val2;
            case '-':
                return val1 - val2;
            case '*':
                return val1 * val2;
            case '/':
                return val1 / val2;
        }
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums_stk;
        int ans = 0;
        for(string s: tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int val2 = nums_stk.top(); nums_stk.pop();
                int val1 = nums_stk.top(); nums_stk.pop();
                ans = eval_exp(val1, s[0], val2);
                nums_stk.push(ans);
            }
            else nums_stk.push(my_stoi(s));
        }

        return nums_stk.top();
    }
};