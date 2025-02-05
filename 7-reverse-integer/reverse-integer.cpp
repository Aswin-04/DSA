class Solution {
public:
    int reverse(int x) {
        int reverseNum = 0;
        int num = x;

        while(num) {
            if(reverseNum > INT_MAX/10 || reverseNum < INT_MIN/10) return 0;
            reverseNum = (reverseNum*10) + (num%10);
            num/=10;
        }

        return reverseNum;
    }
};