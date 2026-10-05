class Solution {
    public List<Integer> getRow(int rowIndex) {
        
        List<Integer> res = new ArrayList<>();
        long ans = 1;
        res.add((int) ans);

        for(int col = 0; col < rowIndex; col++) {
            ans = ans * (rowIndex-col);
            ans = ans / (col+1);
            res.add((int) ans);
        }

        return res;
    }
}