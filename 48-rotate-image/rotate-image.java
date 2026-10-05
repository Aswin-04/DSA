class Solution {
    public void rotate(int[][] matrix) {
        
        int n = matrix.length;

        for(int i=0; i < n; i++) {
            for(int j=i+1; j < n; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for(int i=0; i < n; i++) {
            reverse(matrix, i, n);
        }
    }

    private void reverse(int[][] matrix, int row, int n) {

        for(int i=0; i < n/2; i++) {
            int tmp = matrix[row][i];
            matrix[row][i] = matrix[row][n-i-1];
            matrix[row][n-i-1] = tmp;
        }
    } 
}