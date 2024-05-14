class Solution {
public:
    int totalGold(vector<vector<int>>& grid,int rows, int cols,int currentRow,int currentCol)
    {
        if(rows < 0  || cols < 0 || currentRow < 0 || currentCol < 0 || currentRow >= rows || currentCol >= cols || grid[currentRow][currentCol] == 0) 
        {
            return 0;
        }
        int currentCellGold = grid[currentRow][currentCol];
        grid[currentRow][currentCol] = 0;

        int maxGold = 0;
        maxGold = max(maxGold, totalGold(grid,rows,cols,currentRow +1 ,currentCol)); //Below Row +1
        maxGold = max(maxGold, totalGold(grid,rows,cols,currentRow ,currentCol+1)); //Right Col + 1
        maxGold = max(maxGold, totalGold(grid,rows,cols,currentRow ,currentCol - 1)); //Left col - 1
        maxGold = max(maxGold, totalGold(grid,rows,cols,currentRow -1 ,currentCol)); // row - 1
    grid[currentRow][currentCol] = currentCellGold;
    // cout<<"Idhar aa gaya";
        return currentCellGold+maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        int ans = 0 ;
        for(int i = 0; i < totalRows ; i++)
        {
            for(int j = 0; j < totalCols ; j++)
            {
                ans = max(ans , totalGold(grid,totalRows,totalCols,i,j));
            }
        } 
        return ans;
    }
};