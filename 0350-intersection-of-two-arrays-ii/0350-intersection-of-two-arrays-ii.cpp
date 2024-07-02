class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int pointer1=0,pointer2=0;
        while( pointer1 < nums1.size() && pointer2 <nums2.size())
        {
            if(nums1[pointer1] == nums2[pointer2])
            {
                ans.push_back(nums1[pointer1]);
                pointer1++;
                pointer2++;
            }
            else if(nums1[pointer1] > nums2[pointer2])
            {
                pointer2++;
            }
            else
            {
                pointer1++;
            }
        } 
        return ans;
    }
};