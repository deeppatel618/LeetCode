class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int [] chars = new int[128];
        int left = 0;
        int right = 0;
        int r,l;
        while(right < s.length()){
            r = s.charAt(right);
            chars[r] ++;
            
            while(chars[r] > 1 ){
                l = s.charAt(left);
                chars[l] --;
                left++;
            }
            
            ans = Math.max(ans, right - left + 1);
            right ++;
        }
        return ans;
        
    }
}