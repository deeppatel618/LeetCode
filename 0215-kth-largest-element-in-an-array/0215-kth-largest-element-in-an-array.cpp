class Solution {
public:
    // Approach 1 - Easy
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int ans=-1;
        for(auto i: nums)
        {
            pq.push(-i);
            if(pq.size() > k)
                pq.pop();
        }
        return -pq.top();
    }




    // Approach 2 - quick select
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,k);
    }
    int quickSelect(vector<int> &nums,int k){
        // Select pivot at random.
        int pivot = nums[rand() % nums.size()];

        vector<int> left;
        vector<int> mid;
        vector<int> right;

        for(int num:nums){
            if(num > pivot){
                left.push_back(num);
            }
            else if(num<pivot){
                right.push_back(num);
            }
            else{
                mid.push_back(num);
            }
        }

        if(k <= left.size()){
            return quickSelect(left,k);
        }

        if(left.size() + mid.size() < k){
            return quickSelect(right, k - left.size() - mid.size());
        }
        return pivot;
    }
};