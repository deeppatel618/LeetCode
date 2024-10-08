class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int ans=-1;
        for(auto i: nums)
        {
            pq.push(i);
        }
        for(int i =1;i<=k ;i++)
        {
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};