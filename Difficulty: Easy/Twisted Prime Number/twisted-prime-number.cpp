// User function template for C++

class Solution {
  public:
    bool isPrime(int n) {
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n%2 == 0) return false;
        for(int i=3; i*i <= n; i+=2) {
            if(n%i == 0) return false;
        }
        
        return true;
    }
    
    int reverseNum(int num) {
        int sign=1;
        if(num < 0) {
            sign = -1;
            num = -num;
        }
        
        int revNum = 0;
        while(num) {
            int rem = num%10;
            if((1LL*revNum*10)+rem > INT_MAX) return -1;
            revNum = (revNum*10) + rem;
            num/=10;
        }
        
        return sign*revNum; 
    }
    
    int isTwistedPrime(int N) {
        // code here
        return isPrime(N) && isPrime(reverseNum(N));
        
    }
};