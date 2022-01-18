class Solution {
       public int[] sortedSquares(int[] nums) {
        int pos = 0;
        int neg = 0;
        int cindex = 0;
        int ansIndex = 0;
        int ans[] = new int[nums.length];
        for(int i : nums){
            if(i>=0)
                break;
            cindex++;
        }
        pos = cindex;
        neg = cindex-1;
        while(neg>=0 && pos < nums.length){
            if(nums[neg]*-1 < nums[pos]){
                ans[ansIndex++] = nums[neg]*nums[neg];
                neg--;
            }
            else{
                ans[ansIndex++] = nums[pos]*nums[pos];
                pos++;
            }
        }
        while(neg>=0){
            ans[ansIndex++] =nums[neg]*nums[neg];
            neg--;
        }
        while(pos < nums.length){
            ans[ansIndex++] = nums[pos]*nums[pos];
             pos++;
        }
        return ans;   
    }

}