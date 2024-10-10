class Solution {
public:
    int missingNumber(vector<int>& nums) {
       //Approach 1 
       int missingNumber = nums.size();
       for(int i=0;i<nums.size();i++)
       {
            missingNumber ^= i^ nums[i];
       } 
       return missingNumber;
    }
};