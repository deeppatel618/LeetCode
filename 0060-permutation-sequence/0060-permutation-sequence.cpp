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
        if (nums.empty()) // Base case: if no numbers are left
            return;

        int n = nums.size();
        int total = numberOfPermutation(n - 1); // (n-1)! permutations per digit slot

        // Determine which block/slab the k-th permutation is in
        int index = (k - 1) / total;
        ans += to_string(nums[index]); // Append the current digit to the answer

        // Remove the used digit from the list
        nums.erase(nums.begin() + index);

        // Recurse for the next digit with adjusted k
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