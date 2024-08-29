class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter =0;
        int candidate = -1;
        for(auto i : nums)
        {
            if(counter == 0)
            {
                candidate = i;
                counter++;
            }
            else if(i == candidate)
                counter ++;
            else 
                counter --;
        }
        return candidate;
    }
};