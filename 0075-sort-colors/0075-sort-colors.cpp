class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero_counter=0;
       int one_counter=1;
       for(int i=0; i< nums.size();i++)
       {
            if(nums[i] == 0)
                zero_counter++;
            else if(nums[i] == 1)
                one_counter++;
       }
        for(int i=0; i< zero_counter;i++)
            nums[i] = 0;
        for(int i=zero_counter; i < zero_counter+one_counter -1;i++)
            nums[i] = 1;
        for(int i=zero_counter+one_counter -1; i< nums.size();i++)
            nums[i] = 2;
        
    }
};