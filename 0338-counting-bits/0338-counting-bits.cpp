class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        int counter = 0;
        while(true)
        {
            int temp = ans.size();
            for(int i=0; i<temp;i++)
            {
                ans.push_back(ans[i]+1);
                if(ans.size() == n+1)
                {
                    return ans;
                }
            }
        }
        return {};
    }
};