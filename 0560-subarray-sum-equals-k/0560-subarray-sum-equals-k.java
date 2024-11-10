class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> ans=new HashMap<>();
        int total=0;
        int counter=0;
        ans.put(0,1);// for storing 0 as sum so we can consider values from 0 index
        for(int i=0;i<nums.length;i++)
        {
            total+=nums[i];
            if(ans.containsKey(total-k))
            {
                counter+=ans.get(total-k);
            }
           ans.put(total,ans.getOrDefault(total,0)+1);
        }
        return counter;
    }
}