class Solution {
public:
    int calculate(vector<int> nums){
        int prev = nums[0]; // index 0
        int prev2 = 0; // for now it is index -1

        int pick,notPick,curr;
        for(int i = 1;i<nums.size() ; i++)
        {
            pick = nums[i]+prev2;
            notPick = prev;
            curr = max(pick,notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; 
        vector<int> arr1;
        vector<int> arr2;
        
        for(int i = 0; i<n;i++){
            if(i != 0) arr1.push_back(nums[i]);
            if(i != n-1) arr2.push_back(nums[i]);
        }
        return max(calculate(arr1) ,calculate(arr2));
    }
};