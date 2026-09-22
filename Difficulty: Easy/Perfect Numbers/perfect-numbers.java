class Solution {
    static boolean isPerfect(int n) {
        // code here
        int sum = 0;
        for(int i=1; i*i <= n; i++) {
            if(n%i != 0) continue;
            sum+=i;
            if(n/i != n && i != n/i) sum += (n/i);
        }
        
        return sum == n;
    }
};