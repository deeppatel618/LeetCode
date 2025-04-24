class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,0));
        vector<vector<int>> distance(rows,vector<int>(cols,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            // Separate the data
            auto topElement = q.front();
            int row = topElement.first.first;
            int col = topElement.first.second;
            int dist = topElement.second;
            q.pop();


            distance[row][col] = dist;

            for(auto direction:directions){
                int neighborRow = direction[0]+row;
                int neighborCol = direction[1]+col;

                if(neighborRow>=0 && neighborRow<rows && neighborCol>=0 && neighborCol<cols && visited[neighborRow][neighborCol] == 0)
                {
                    if(mat[neighborRow][neighborCol] == 1){
                        visited[neighborRow][neighborCol] =1;
                        q.push({{neighborRow,neighborCol},dist+1});
                    }
                }
            }

        }
        return distance;
    }
};