class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0, right = height.size()-1;
        int ans = -1;
        while(left<right)
        {
            int totalCap = (right - left) * min(height[left],height[right]);
            ans = max(totalCap,ans);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right --;
            }
        }
        return ans;
    }
};