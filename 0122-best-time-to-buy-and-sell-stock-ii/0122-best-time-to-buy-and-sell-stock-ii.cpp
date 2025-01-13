class Solution {
public:
    // Find dip(valley) and high (peak) in the array. Add them.
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int minValue = prices[i]; 
        int maxValue = prices[i]; 
        int maxProfit = 0;
        while(i < prices.size() - 1)
        {
            while(i < prices.size() - 1 && prices[i]>=prices[i+1]) i++;
            minValue = prices[i];
            while(i < prices.size() - 1 && prices[i]<=prices[i+1]) i++;
            maxValue = prices[i];
            maxProfit += (maxValue-minValue);
        }
        return maxProfit;
    }
    //O(n) O(1)
};