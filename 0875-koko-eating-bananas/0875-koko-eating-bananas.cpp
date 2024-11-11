class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(),piles.end());
        int left = 1,mid;
        int hours;
        while(left<right)
        {
            mid = (left+right)/2;
            hours = 0;
            for(int pile:piles)
            {
                hours+= pile/mid + (pile%mid != 0);
            }
            // cout<<hours;
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
    }
    
};