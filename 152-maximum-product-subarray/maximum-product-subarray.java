class Solution {
    public int maxProduct(int[] nums) {
        
        int n = nums.length;
        int pref = 1;
        int suff = 1;
        int maxProd = -11;

        for(int i=0; i < n; i++) {
            pref*=nums[i];
            maxProd = Math.max(maxProd, pref);

            suff*=nums[n-i-1];
            maxProd = Math.max(maxProd, suff);

            if(pref == 0) 
                pref = 1;
            
            if(suff == 0)
                suff = 1;
        }

        return maxProd;
    }
}