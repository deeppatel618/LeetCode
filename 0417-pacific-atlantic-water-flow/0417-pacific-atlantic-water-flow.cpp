class Solution {
public:
    // Instead of traversing all the cells, reverse the condition and start traversing from border of the matrix. Traverse untill the next element is greater and mark it as 1. 
    // Do this for pacific and atlantic. Intersection of both the matrix will be answer.
    // This means that water from pacific or atlantic can flow to that location in reverse direction. 
    void dfs(int row, int col,vector<vector<int>>& heights, int previous,vector<vector<int>>& marker)
    {
        if(row<0 || col<0 || row>= heights.size() || col >= heights[0].size() || previous > heights[row][col] || marker[row][col] == 1)
        return ;
        
        marker[row][col] = 1; // The cell is reachable
        previous = heights[row][col]; // Update the previous.

        dfs(row+1,col,heights,previous,marker);
        dfs(row-1,col,heights,previous,marker);
        dfs(row,col+1,heights,previous,marker);
        dfs(row,col-1,heights,previous,marker);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int previous;

        vector<vector<int>> pacific(rows,vector<int>(cols,0));
        vector<vector<int>> atlantic(rows,vector<int>(cols,0));


        for(int i = 0; i< heights.size(); i++) // traverse 1st and last col.
        {
            dfs(i,0,heights, -1, pacific);
            dfs(i,heights[0].size()-1,heights, -1, atlantic);
        }
        for(int i = 0; i< heights[0].size(); i++) // traverse 1st and lastrow.
        {
            dfs(0,i,heights, -1, pacific);
            dfs(heights.size()-1,i,heights, -1, atlantic);
        }

        vector<vector<int>> ans;
        for(int i = 0; i< heights.size(); i++)
        {
            for(int j = 0; j< heights[0].size(); j++)
            {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        // O(M*N) we are traversing all the nodes only once.
        // O(M*N) Stack space if all the nodes are reachable from one point.
    }
};