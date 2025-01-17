class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxp=0;
        int minp=prices[0];
        for(int v=1;v<prices.size();v++)
        {
            if(maxp<prices[v]-minp)
            {
                maxp=prices[v]-minp;}
            if(minp>prices[v]){
                minp=prices[v];}
        }
        return maxp;
    }
};