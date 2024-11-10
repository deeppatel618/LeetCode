class Solution {
public:
    void transpose(vector<vector<int>> &matrix)
    {
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = i;j<matrix[0].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void reverse(vector<vector<int>>& matrix)
    {
        for(int i = 0;i<matrix.size();i++)
        {
            int n = matrix.size();
            for(int j = 0;j<matrix[0].size()/2;j++)
            {
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {

        // //Transpose and reverse the row.
        // for(int i = 0; i < matrix[0].size(); i++ )
        // {
        //     for(int j = i; j < matrix[0].size(); j++)
        //     {
        //         if(i!=j)
        //         {
        //             swap(matrix[i][j],matrix[j][i]);
        //         }
        //     }
        // }
        // for(int i = 0; i< matrix[0].size();i++)
        // {
        //     reverse(matrix[i].begin(), matrix[i].end());
        // }

        // int n = matrix.size();
        // for(int i = 0; i< (n+1)/2;i++)
        // {
        //     for(int j = 0; j < n/2; j++)
        //     {
        //         int temp = matrix[n-1-j][i];
        //         matrix[n-1-j][i] = matrix[n-1-i][n-j-1];
        //         matrix[n-1-i][n-j-1] = matrix[j][n-1-i];
        //         matrix[j][n-1-i] = matrix[i][j];
        //         matrix[i][j] = temp;
        //     }
        // } 
        transpose(matrix);
        reverse(matrix);
    }
};