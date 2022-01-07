class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
     if (r * c != mat.length * mat[0].length) return mat;
        int[][] ans = new int[r][c];
        int row=0,col=0;
        for (int i = 0; i < mat.length; i++)
        {
            for (int j = 0; j < mat[i].length; j++)
            {
                ans[row][col] = mat[i][j];
                if(col < c-1)
                {
                    col++;
                }
                else if(row < r-1)
                {
                    row++;
                    col=0;
                }
            }
        }
        return ans;
    }
}