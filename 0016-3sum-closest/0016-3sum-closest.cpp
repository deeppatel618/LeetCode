class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //Sorting
        sort(nums.begin(),nums.end());

        int closest = INT_MAX;
        int sum = 0;
        for(int i = 0; i< nums.size()-2;i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            int reqSum = target - nums[i];
            while(j<k)
            {
                if(abs(closest) > abs(nums[j]+nums[k]+nums[i] - target))
                {
                    closest = abs(nums[j]+nums[k]+nums[i] - target);
                    sum = nums[j]+nums[k]+nums[i];
                }
                if(reqSum > (nums[j] +nums[k]))
                {
                    j++;
                }
                else if (reqSum < (nums[j] +nums[k]))
                {
                    k--;
                }
                else
                {
                    return nums[i]+nums[j]+nums[k];
                }
            }
        }
        return sum;
    }
};