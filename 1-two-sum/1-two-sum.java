class Solution {
    public int[] twoSum(int[] nums, int target) {
      HashMap<Integer,Integer> hash= new HashMap<>();
        int[] a = new int[2];
        for(int i=0 ; i< nums.length ; i++)
        {
            hash.put(nums[i],i);
        }
        for(int i=0 ; i< nums.length ; i++){
            if(hash.containsKey(target - nums[i]))
            {
                if (hash.get(target - nums[i]) !=i) {
                    a[0] = i;
                    a[1] = hash.get(target - nums[i]);
                    break;
                }
            }
        }
        return a;
    }
}