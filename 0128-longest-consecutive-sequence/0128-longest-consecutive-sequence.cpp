class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        int ans=0;
        unordered_set<int> numsSet(nums.begin(),nums.end());
        for(int i:numsSet)
        {
            if(!numsSet.count(i-1) )
            {
                int counter = 1;
                while(numsSet.count(i+counter)) counter++;
                ans = max(counter,ans);
            }
        }
        return ans;
        
    }
};