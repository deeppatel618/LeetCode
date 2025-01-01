class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long total = 0;
        int left = 0;
        int maxFreq = 1;
        for(int right = 0; right<nums.size(); right++)
        {
            long curr =nums[right];
            total+=curr;
            // if((curr * (right - left +1)) <= (total+k)){
            //     maxFreq = max(maxFreq , right - left +1 );
            // }
            // else{
                while((curr * (right - left +1)) > (total+k) && left<=right)
                {
                    total -= nums[left];
                    left++;
                }
            // }
                maxFreq = max(maxFreq , right - left +1 );
        }
        return maxFreq;
    }
};