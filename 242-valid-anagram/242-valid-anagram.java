class Solution {
    public boolean isAnagram(String s, String t) {
       if(s.length() != t.length()) return false;
        int[] charArr=new int[26];
        for (int i = 0; i <s.length(); i++) {
            charArr[ s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            if(charArr[t.charAt(i) - 'a'] ==0) return false;
            charArr[t.charAt(i) - 'a']--;
        }
        return true;
    }
}