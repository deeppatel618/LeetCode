class Solution {
public:
    // Cummilative sum and store it in map.
    // Use a hash map (mp) to store how many times each cumulative sum has occurred.
    // Logic - explain using an array which stores cumulative sum of and find out difference between 2 indices
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp(nums.size());
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i<nums.size();i++)
        {
            sum += nums[i];
            int key = sum -k;
            if(mp.find(key) !=mp.end())
            {
                ans+=mp.find(key)->second;
            }
            mp[sum]++;
            for(auto it:mp)
            {
                cout<<it.first<<" -> "<<it.second<<endl;
            }
            cout<<"Done for now"<<endl;
        }
        return ans;
        //O(n) O(n)
    }
};