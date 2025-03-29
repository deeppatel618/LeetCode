class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(int i = 0; i<nums.size() ;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it: mp){
            minHeap.push({it.second,it.first});

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
         while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};