class Solution {
    public boolean boxes[][] = new boolean[9][9];
    public boolean cols[][] = new boolean[9][9];
    public boolean rows[][] = new boolean[9][9];
    int n = 0;
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] =='.')
                    continue;
                n = board[i][j] -'0' - 1;
                if(rows[i][n])
                    return false;
                if(cols[j][n])
                    return false;
                if(boxes[(i/3)*3 + j/3][n])
                    return false;
                rows[i][n] = true;
                cols[j][n] = true;
                boxes[(i/3)*3 + j/3][n] = true;
            }
        }
        return true;
    }
}