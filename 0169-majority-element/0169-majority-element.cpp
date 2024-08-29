class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter =0;
        int candidate = -1;
        for(int i=0; i< nums.size();i++)
        {
            if(counter == 0)
            {
                candidate = nums[i];
                counter++;
            }
            else if(nums[i] == candidate)
                counter ++;
            else 
                counter --;
        }
        return candidate;
    }
};