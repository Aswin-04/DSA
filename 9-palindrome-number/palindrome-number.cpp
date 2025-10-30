class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        int num = x;
        int ans = 0;

        while(num) {
            if(ans > INT_MAX/10) return false;
            ans = (ans*10) + (num%10);
            num/=10;
        }

        return ans == x;
    }
};
