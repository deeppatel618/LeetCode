class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int x, y;
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size() > 1)
        {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            if(x!=y)
                pq.push(abs(x-y));
        }
        return pq.empty()? 0: pq.top();
    }
};