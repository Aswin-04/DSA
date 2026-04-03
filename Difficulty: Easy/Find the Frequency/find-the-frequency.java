class Solution {
    int findFrequency(int arr[], int x) {
        // code here
        HashMap<Integer, Integer> freq = new HashMap<>();
        for(int i=0; i < arr.length; i++) {
            int val = arr[i];
            freq.put(val, freq.getOrDefault(val, 0) + 1);
        }
        
        return freq.getOrDefault(x, 0);
    }
}