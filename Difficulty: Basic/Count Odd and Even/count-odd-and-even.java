class Solution {
    public int[] countOddEven(int[] arr) {
        // Code here
        int odd = 0;
        for(int i=0; i < arr.length; i++) {
            if(arr[i]%2 != 0) odd++;
        }
        
        return new int[]{odd, arr.length-odd};
    }
}