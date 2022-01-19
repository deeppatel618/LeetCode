class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans=new int[2];  
        int left=0;
        int right=nums.length-1;
        while(left<=right)
        {
            if(nums[left]+ nums[right] == target) break;
            if(nums[left]+ nums[right]< target) left++;
            else if(nums[left]+ nums[right]> target) right--;
        }
        ans[0]=left+1;
        ans[1]=right+1;
        return ans;
    }
}