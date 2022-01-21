public class Solution {
    public int lengthOfLongestSubstring(String s) {
        boolean[] chars = new boolean[128];

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s.charAt(right);
            
            while (chars[r]) {
                char l = s.charAt(left);
                chars[l] = false;
                left++;
            }
            chars[r] = true;


            res = Math.max(res, right - left + 1);

            right++;
        }
        return res;
    }
}