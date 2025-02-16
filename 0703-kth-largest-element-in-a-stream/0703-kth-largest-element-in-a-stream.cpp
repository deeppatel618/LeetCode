class KthLargest {
public:
    int k = 0;
    priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i: nums)
        {
            pq.push(-i);
        }
        while(pq.size() > k )
        {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-val);
        while(pq.size() > k)
            pq.pop();

        return -1*(pq.top());
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */