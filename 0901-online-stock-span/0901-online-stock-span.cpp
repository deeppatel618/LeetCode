class StockSpanner {
public:
    stack<pair<int,int>> priceSt;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!priceSt.empty() && priceSt.top().first<= price)
        {
            ans += priceSt.top().second;
            priceSt.pop();
        }
        priceSt.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */