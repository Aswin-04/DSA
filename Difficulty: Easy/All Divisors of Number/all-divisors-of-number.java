class Solution {
    public ArrayList<Integer> getDivisors(int n) {
        // code here
        ArrayList<Integer> divisors = new ArrayList<Integer>();
        
        for(int i=1; i*i <= n; i++) {
            if(n%i == 0) {
                divisors.add(i);
                if(i != n/i) {
                    divisors.add(n/i);
                }
            }
        }
        
        Collections.sort(divisors);
        return divisors;
    }
}