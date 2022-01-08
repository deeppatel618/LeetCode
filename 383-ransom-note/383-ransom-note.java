class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] charArr=new int[26];
        for (int i = 0; i <magazine.length(); i++) {
            charArr[ magazine.charAt(i) - 'a']++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            if(charArr[ransomNote.charAt(i) - 'a'] ==0) return false;
            charArr[ransomNote.charAt(i) - 'a']--;
        }
        return true;
    }
}