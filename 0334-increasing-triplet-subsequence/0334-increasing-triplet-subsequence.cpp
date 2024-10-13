class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_number = INT_MAX;
        int second_number = INT_MAX;
        for(int i:nums)
        {
            if( i <= first_number)
            {
                first_number = i;
            }
            else if(i<= second_number)
            {
                second_number = i;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};