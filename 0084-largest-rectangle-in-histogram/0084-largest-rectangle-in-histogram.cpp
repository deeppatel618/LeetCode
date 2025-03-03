class Solution {
public:
    // If we compute previous smaller element and next smaller element array, we can easily compute the answer by formula currentElement *(nextSmallerElementIndex - previousSmallerElementIndex - 1);
    // But if we compute it separately then it is not efficient.

    // To do it efficiently we can calculate the nse and pse on the go.
    // Use stack to keep track of previous smaller element. when the top of element is greater than the current element, than the elements have discovered nextsmallerElement(which is the current element) and the previous smaller element which is the second number on the stack.
    // This way we can find nse and pse for all the elements. 
    // If there is no pse than consider -1 as imaginary smaller element and for nse consider size() of the array as next smaller index.
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
    //O(n) O(n)
};