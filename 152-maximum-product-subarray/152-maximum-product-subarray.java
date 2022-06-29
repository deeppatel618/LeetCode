class Solution {
   public int maxProduct(int[] nums) 
  {
      if(nums.length == 1)    return nums[0];
      
      int max = nums[0];
      int product = 1;
      
      for(int n : nums)
      {
          product *= n;
          max = Math.max(max, product);
          
            if(n == 0)
              product = 1;
      }
      
      product = 1;
      for(int i = nums.length-1; i >= 0; i--)
      {
          product *= nums[i];
          max = Math.max(max, product);
          
         if(nums[i] == 0)
              product = 1;
      }
      return max;
  }
}