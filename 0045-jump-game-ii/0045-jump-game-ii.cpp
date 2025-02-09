class Solution {
public:
    
    int jump(vector<int>& nums) {
        // Kind of BFS on array. Consider first element from [2,3,1,1,4] and see the range where it can reach. It can reach from index 1 to 2 which will be our left and right pointer. Now consider the left and rigt range that is index 1 - 2 and find the next index. If at any point of time if the right is >= size of the array. Return the jumps. 
        int jumps = 0 ;
        int left = 0, right = 0;
        while(right < nums.size() -1)
        {
            int farthest = 0 ;
            for(int i = left; i <=right; i++)
            {
                farthest = max(farthest, i+nums[i]);
            }
            left = right+1;
            right = farthest;
            jumps+=1;
        }
        return jumps;
    }
    //O(n) O(1)
};