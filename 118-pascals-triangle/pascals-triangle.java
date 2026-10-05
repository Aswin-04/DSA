class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> res = new ArrayList<>(numRows);

        for(int row = 1; row <= numRows; row++) {

            int ans = 1;
            List<Integer> crntRow = new ArrayList<>();
            crntRow.add(ans);

            for(int col=1; col < row; col++) {
                ans = ans * (row-col);
                ans = ans / col;
                crntRow.add(ans);
            }

            res.add(crntRow);
        }

        return res;
    }
}