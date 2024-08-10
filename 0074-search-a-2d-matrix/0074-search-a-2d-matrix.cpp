class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first=0;
        int i=matrix.size(); // 3
        int j=matrix[0].size(); // 4 
        int last = (i*j)-1;
        int middle;
        while(first<=last)
        {
            middle =(last+first)/2;
           if(matrix[int(middle/j)][middle%j] == target)
           {
            return true;
           }
           if(matrix[int(middle/j)][middle%j] > target)
                last = middle-1;
           else
                first = middle+1;
            // cout<<"last = "<<last<<" first = "<<first<<" Middle"<<middle<<" "<<int(middle/j)<<","<<int(middle%j)<<endl;
           
        }
        return false;
    }
};