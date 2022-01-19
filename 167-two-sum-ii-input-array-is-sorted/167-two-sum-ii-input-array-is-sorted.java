class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans=new int[2];  
        int left=0;
        int right=nums.length-1;
        int sum;
        while(left<=right)
        { 
            sum=nums[left]+ nums[right];
            if(sum == target) break;
            if(sum< target) left++;
            else if(sum> target) right--;
        }
        ans[0]=left+1;
        ans[1]=right+1;
        return ans;
    }
}