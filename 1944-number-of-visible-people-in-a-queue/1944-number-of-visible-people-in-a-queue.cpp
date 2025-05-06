class Solution {
public:
    // Use monotonic stack.
    // Remove all shorter height people and increase the count
    // if the stack has someone greater, include that person as he will be in the answer
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer(n, 0);
        stack<int> st;  // Stack holds indices of people to the right

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            int count = 0;

            // Pop all people shorter than current → they are visible
            while (!st.empty() && heights[i] > heights[st.top()]) {
                st.pop();
                ++count;
            }

            // If there's still someone on stack → taller/next blocker, also visible
            if (!st.empty()) {
                ++count;
            }

            answer[i] = count;
            st.push(i);  // Push current person to stack
        }

        return answer;
    }
    // O(n)
    // O(1)
};

