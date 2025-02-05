class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        int num = x;
        long long ans = 0;

        while(num) {
            ans = (ans*10) + (num%10);
            num/=10;
        }

        return ans == x;
    }
};