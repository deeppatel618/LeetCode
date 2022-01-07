class Solution {
    public int maxProfit(int[] prices) {
      int max=-1,diff=-1;
        int min=prices[0];
        for (int i = 1; i <prices.length ; i++) {
            if(prices[i]>max)
            {
                max=prices[i];
                if(diff<max-min) diff=max-min;
            }
            if(prices[i] < min) {
                min = prices[i];
                max = -1;
            }
        }
        return diff>0?diff:0;
    }
}