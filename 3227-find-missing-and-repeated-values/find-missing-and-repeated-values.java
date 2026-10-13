class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int size = n*n;
        int[] count = new int[size+1];

        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }

        int rep = 0, miss = 0;

        for(int num=1; num <= size; num++) {
            if(count[num] == 2) 
                rep = num;
            if(count[num] == 0)
                miss = num;
        }

        return new int[] {rep, miss};
    }
}