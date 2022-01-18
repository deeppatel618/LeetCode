class Solution {
        public int[] sortedSquares(int[] nums) {
        int index=0,temp;
        for(int i=0;i< nums.length;i++)
        {
            index= i;
            temp= (int) Math.pow(nums[i],2);
            while( index > 0 && temp < nums[index-1] )
            {
                nums[index]=nums[index-1];
                index--;
            }
            nums[index]=temp;
        }
        return nums;
    }

}