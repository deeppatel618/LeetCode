class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Binary search with number of working hours.
        int right = *max_element(piles.begin(),piles.end());
        int left = 1,mid;
        int hours;
        while(left<right)
        {
            mid = (left+right)/2;
            hours = 0;
            // checking the selected value of "hour" for all the piles.
            for(int pile:piles)
            {
                hours+= pile/mid + (pile%mid != 0);
            }
            // Checking if the working hour is below the limit or not
            if(hours<=h)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return right;
        // O(n⋅logm) n = length of the array. M is max element in the array.
        //O(1) 
    }
    
};