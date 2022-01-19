class Solution {
    public void moveZeroes(int[] nums) {
        if(nums.length ==1 && nums[0]==0) return;
        int index=0;
        int length=nums.length;
        for (int i = 0; i < length; i++) {
            if(nums[i]==0) index++;
            else {
                nums[i-index]=nums[i];
            }
        }
        for (int i = length-index; i < length; i++) {
            nums[i]=0;
        }
    }
}