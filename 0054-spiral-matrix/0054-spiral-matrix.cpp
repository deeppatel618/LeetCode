class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int right = cols-1;
        int down = rows-1;
        int left = 0;
        int up = 0;
        while(results.size()< rows*cols)
        {
            //Traverse from left to right
            for(int col = left; col<=right;col++)
            {
                results.push_back(matrix[up][col]);
            }
            // Traverse from up to down
            for(int row = up+1; row<=down;row++)
            {
                results.push_back(matrix[row][right]);
            }

            if(up!= down)
            { // Traverse from left to down
                for(int col = right - 1; col>=left;col-- )
                {
                   results.push_back(matrix[down][col]); 
                }
            }
            if (left != right) {
                // Traverse upwards.
                for (int row = down - 1; row > up; row--) {
                    results.push_back(matrix[row][left]);
                }
            }
            up++;
            left++;
            right--;
            down--;
        }
        return results;

    }
};