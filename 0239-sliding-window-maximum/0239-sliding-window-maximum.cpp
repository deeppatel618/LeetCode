class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Logic is to maintin the window of k using deque.
        // Everytime increasing right side of the window check if left is inside or outside size k. If outside then remove the element from the deque. It will be stored in the front.

        // For max number, compare the current element with deque's back (i.e top). remove all the elements which are smaller and will never be used after this point.

        // Add every element on the stack as it might be smaller for current window but can be used for next window. 
        deque<int> dq;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){

            if(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
        // One pass - O(N)
        // Space - O(K). We are storing max K elements in thr deque.
    }
};