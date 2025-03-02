class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int ptr1 = 0;
        int ptr2 = 0;
        vector<vector<int>> result;
        while(ptr1 < nums1.size() && ptr2 < nums2.size()){
            if(nums1[ptr1][0] == nums2[ptr2][0]){
                result.push_back({nums1[ptr1][0], nums1[ptr1][1]+nums2[ptr2][1]});
                ptr1++;
                ptr2++;
            }else if(nums1[ptr1][0]>nums2[ptr2][0]){
                result.push_back(nums2[ptr2]);
                ptr2++;
            }
            else{
                result.push_back(nums1[ptr1]);
                
                ptr1++;
            }
        }
        while(ptr1 < nums1.size()){
            result.push_back(nums1[ptr1]);    
            ptr1++;
        }
        while(ptr2 < nums2.size()){
            result.push_back(nums2[ptr2]);    
            ptr2++;
        }
        return result;
    }
};