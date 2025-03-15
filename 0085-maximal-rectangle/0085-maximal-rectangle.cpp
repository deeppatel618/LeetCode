class Solution {
public:
    // The logic of this code is same as Largest Rectangle in Histogram.
    
    // But before that assume each row of the matrix as one so, the buildings would be 1,0,1,0,1
    // If we consider each row as buildings than we can say that max area for this is 1
    // If we calculate prefix sum for each column than we can also check for the biggest rectangle in the matrix.
    // While calculating the prefix sum for each col make sure you reset the sum to 0 as the rectangle will be broken from that point.
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> prefixSum(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i = 0; i < matrix[0].size();i++){
            int count = 0;
            for(int j = 0; j < matrix.size();j++){
                if(matrix[j][i] - '0' != 0){
                    count+=matrix[j][i] - '0';
                    // cout<<matrix[j][i]<<"j and i"<<j<<" "<<i<<endl;
                    prefixSum[j][i] = count;
                }
                else{
                    count = 0;
                    prefixSum[j][i] = 0;
                }
            }
        }
        int maximumRect = 0;
        for(int i = 0; i < prefixSum.size(); i++){
            maximumRect = max(maximumRect,largestRectangleArea(prefixSum[i]));
        }
        return maximumRect;
        
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){ // the current element is smaller
                int elementIndex = st.top();
                st.pop();
                int nextSmallerElement = i;
                int previousSmallerElement = st.empty()? -1 : st.top();
                int currentArea = heights[elementIndex] * (nextSmallerElement - previousSmallerElement - 1);
                maxArea = max(maxArea, currentArea);
            }
            st.push(i);    
        }
        // Computing for remaining element.
        while(!st.empty()){
            int nextSmallerElement = heights.size(); // imaginary last element.
            int elementIndex = st.top();
            st.pop();
            int previousSmallerElement = st.empty()? -1 : st.top();
            maxArea = max(maxArea, heights[elementIndex] * (nextSmallerElement - previousSmallerElement - 1));
        }
        return maxArea;
    }
    // O(mn)
    // O(mn)

};