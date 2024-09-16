class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter=0,ans=0;
        for(auto& i:nums)
        {
            if(i == 1)
            {
                counter += 1;
                ans = max(ans,counter);
            }
            else
                counter =0;
        }
        return ans;
    }
};