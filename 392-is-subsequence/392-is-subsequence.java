class Solution {
    public boolean isSubsequence(String s, String t) {
        int subPointer=0;
        int strPointer=0;
        int strLen=t.length();
        int subLen=s.length();
        if(subLen==0) return true;
        while(strPointer!=strLen && strLen!=0)
        {
            if(t.charAt(strPointer) == s.charAt(subPointer))
            {
                subPointer+=1;
                if( subPointer== subLen) return true;
            }
            strPointer+=1;
        }
        return false;
    }
}