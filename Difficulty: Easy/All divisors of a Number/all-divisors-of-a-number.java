class Solution {
    public static void print_divisors(int n) {
        // code here
        TreeSet<Integer> set = new TreeSet<>();
        
        for(int i=1; i*i <= n; i++) {
            if(n%i == 0) {
                set.add(i);
                if(n/i != i) set.add(n/i);
            }
        }
        
        for(int num: set) {
            System.out.print(num + " ");
        }
    }
}
