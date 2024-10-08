class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l_array(nums.size());
        vector<int> r_array(nums.size());
        l_array[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            l_array[i]=l_array[i-1]*nums[i-1];
        }
        r_array[nums.size()-1]=1;
        for(int j=nums.size()-2;j>=0;j--)
        {
            r_array[j]=r_array[j+1]*nums[j+1];
        }
        for(int i=0;i<=nums.size()-1;i++)
        {
            r_array[i]=r_array[i] * l_array[i];
        }
        return r_array;
    }
};