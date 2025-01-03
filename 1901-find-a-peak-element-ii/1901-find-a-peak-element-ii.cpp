class Solution {
public:
    int findMaxFromCol(vector<vector<int>>& mat, int mid)
    {
        int currMax = 0;
        int index = -1;
        for(int i = 0; i<mat.size();i++)
        {
            if(mat[i][mid]>currMax)
            {
                currMax = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int currMax = 0;
            int index = findMaxFromCol(mat,mid);
            
            int left = mid - 1 >=0? mat[index][mid-1] : -1;
            int right = mid + 1 < mat[0].size()? mat[index][mid+1]:-1;

            if(left < mat[index][mid] && mat[index][mid]>right)
            {
                return {index,mid};
            }
            else if(mat[index][mid] < right)
            {
                low = mid+1;
            }
            else
            {
                high = mid -1;
            }
        }
        return {-1,-1};
    }
};