class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int count = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];
        int complement = k - current;
        if (map[complement] > 0) {
            count++;
            map[complement]--; 
        } else {
            map[current]++;
        }
    }
    
    return count;

    }
};