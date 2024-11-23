class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // Instead of focusing on the variables, Focus on pattern and
        // Instead of counting numbers count patterns.
        // Replace all the number of a row based on its first value. If first element in row is 1 then change it to T and follow pattern for each row. 
        // Do this for all the rows.
        unordered_map<string,int> patterns;
        for(auto row:matrix)
        {
            string currPattern="";
            for(int i = 0;i<row.size();i++)
            {
                if(row[0] == row[i]) // first and anyother element is same
                    currPattern +="T";
                else
                    currPattern +="F";
            }
            patterns[currPattern]++;
        }
        int maxFeq = 0;
        for(auto pattern:patterns)
        {
            maxFeq = max(maxFeq,pattern.second);
        }
        return maxFeq;
    }
    //O(n.m) Traversing whole matrix
    //O(n.m) Storing matrix in the form of pattern
};