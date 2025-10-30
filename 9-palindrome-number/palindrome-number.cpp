class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        int rev_num = 0;
        if(num < 0) return false;
        while(num > 0) {
            int ld = num%10;
            if((1LL*rev_num*10)+ld > INT_MAX || (1LL*rev_num*10)+ld < INT_MIN) return false;
            rev_num = rev_num*10+ld;
            num/=10;
        } 
        cout << rev_num;
        return rev_num == x;
    }
};