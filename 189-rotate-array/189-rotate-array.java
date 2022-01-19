class Solution {
      public void rotate(int[] nums, int k) {
        if(nums == null || nums.length==1) return ;
        int length=nums.length;
        int temp=nums[0];
        int temp1,steps=-1,i=0;
        if(k>length) k%=length;
        int index=k;
       while(steps!=length-1){
            temp=nums[i];
            index=k+i>length-1?k+i-length:k+i;
            while (index != i) {
                steps++;
                temp1 = nums[index];
                nums[index] = temp;
                temp = temp1;
                index += k;
                index = index > length - 1 ? index - length : index;
            }
            steps++;
            nums[index] = temp;
            i++;
        }
    }
}