class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int colCounter=0;
        int rowScore  = (1 << (col - 1 )) * row;
        int colScore = 0;

        for(int i = 1 ; i < col ; i++)
        {
            colCounter = 0;
            for(int j = 0 ; j < row ; j++)
            {
                colCounter+= grid[j][0] == 1 ? grid[j][i]: !grid[j][i];
            }
            colCounter = max(colCounter, row - colCounter);
            // cout<<"Counter value - "<<(1 << (col - i-1 )) * colCounter<<endl;
            colScore += (1 << (col - i-1 )) * colCounter; 

        }
        // cout<<rowScore;
        return rowScore + colScore;
    }
};