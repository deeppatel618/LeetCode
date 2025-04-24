class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,0));
        queue<pair<int,int>> q;
        for(int i = 0; i < rows; i++){
                if(grid[i][0] == 1){
                    q.push({i,0});
                    visited[i][0] = 1;
                }
                if(grid[i][cols-1] == 1){
                    q.push({i,cols-1});
                    visited[i][cols-1] = 1;
                }
        }
        for(int j = 0; j < cols; j++){
                if(grid[0][j] == 1){
                    q.push({0,j});
                    visited[0][j] = 1;
                }
                if(grid[rows-1][j] == 1){
                    q.push({rows-1,j});
                    visited[rows-1][j] = 1;
                }
        }
        // cout<<q.size();
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1},{0,1}};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
           
            for(auto direction:directions){
                int newRow = row + direction[0];
                int newCol = col + direction[1];

                if(newRow >=0 && newRow < rows && newCol >=0 && newCol < cols && visited[newRow][newCol] ==0 && grid[newRow][newCol] == 1){
                    q.push({newRow,newCol});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        int result = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    result++;
                }
            }
        }
        return result;
    }
};