class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans=new ArrayList<>();
        int len=nums.length;
        if(len==0)
            return ans;
        else if (len==1){
            ans.add(Integer.toString(nums[0]));
            return ans;
        }
        else
        {
            int start=nums[0];
            int end=nums[0];
            String adder;
            for (int i = 1; i < len; i++) {
                    if(Math.abs(end-nums[i] )!= 1)
                    {
                        if(start==end)
                            ans.add(Integer.toString(end));
                        else
                        {
                            adder=Integer.toString(start)+"->"+Integer.toString(end);
                            ans.add(adder);
                        }
                        start=nums[i];
                        end=nums[i];
                    }
                    else
                        end=nums[i];
            }
            if(start==end)
                ans.add(Integer.toString(end));
            else
            {
                adder=Integer.toString(start)+"->"+Integer.toString(end);
                ans.add(adder);
            }
        }
        return ans;
    }
}