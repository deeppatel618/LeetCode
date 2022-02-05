class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int r=matrix.length;
        int c=matrix[0].length;
        int row=0;
        for(int i=0;i<r;i++)
        {
            if(target>matrix[i][c-1])
                continue;
            else if(target==matrix[i][c-1])
                return true;
            else {
                row = i;
                break;
            }
        }
        if(target<matrix[row][0])
            return false;
        for(int j=0;j<c;j++)
        {
            if(matrix[row][j]==target)
                return true;
        }
        return false;
    }
}