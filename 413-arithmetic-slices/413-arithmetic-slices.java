class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int counter=0,state=0;
        for(int i=2;i<nums.length;i++)
        {
            if(nums[i-2] - nums[i-1] == nums[i-1]- nums[i])
            {
                state+=1;
                counter+=state;
            }
            else
            {
                state=0;
            }
        }
        return counter;
    }
}