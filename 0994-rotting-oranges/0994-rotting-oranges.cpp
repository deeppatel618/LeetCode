class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Use bfs and add one pair of data through which we can separate the data points.
        int rows = grid.size();
        int cols = grid[0].size();

        int freshOranges = 0;

        queue<pair<int,int>> q;
        for(int i = 0; i < rows;i++)
        {
            for(int j=0; j < cols; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    freshOranges +=1;
            }
        }
        q.push({-1,-1}); // separate each layer.
        
        int time=0;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty())
        {
            pair<int,int> currPair = q.front();
            int currRow = currPair.first;
            int currCol = currPair.second;
            q.pop();

            if(currRow == -1) // {-1,-1}
            {
                
                if(!q.empty())
                {
                    time+=1;
                     q.push({-1,-1});
                }
                   
            }
            else
            {
                for(auto d:dir)
                {
                    int neighborRow = currRow + d[0];
                    int neighborCol = currCol + d[1];

                    if(neighborRow>=0 && neighborRow<rows && neighborCol>=0 && neighborCol<cols)
                    {
                        if(grid[neighborRow][neighborCol] == 1)
                        {
                            freshOranges--;
                            q.push({neighborRow,neighborCol});
                            grid[neighborRow][neighborCol] = 2;

                        }
                    } 
                }
            }

        }

        if(freshOranges == 0)
            return time;
        else
            return -1;

    }
};