class Solution {
public:
    int numberOfPermutation(int n)
    {
        int ans=1;
        while(n>0)
        {
            ans = ans*n;
            n--;
        }
        return ans;
    }
    void permutationCalculator(int k, vector<int> &nums, string &ans)
    {
        if (nums.empty()) 
            return;

        int n = nums.size();
        int total = numberOfPermutation(n - 1); 
        int index = (k - 1) / total;
        ans += to_string(nums[index]); 
        nums.erase(nums.begin() + index);
        k = k - index * total;
        permutationCalculator(k, nums, ans);
    }
    string getPermutation(int n, int k) {
        string ans="";
        vector<int> nums;
        for(int i = 1; i<=n;i++)
        {
            nums.push_back(i);
        }
        permutationCalculator(k,nums,ans);
        return ans;
    }
};