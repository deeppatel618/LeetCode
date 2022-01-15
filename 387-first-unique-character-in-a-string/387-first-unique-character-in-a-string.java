class Solution {
    int[] a =new int[27];
    public int firstUniqChar(String s) {
        for(int i = 0 ; i < s.length() ; i++ )
        {
            a[s.charAt(i) - 'a']+=1;
        }
        for(int i = 0 ; i < s.length(); i++ )
        {
            if(a[ s.charAt(i) - 'a']==1) return i;
        }
        return -1;
    }
}