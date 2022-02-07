class Solution {
    public boolean isPalindrome(int x) {
        boolean flag=true;
        String str=String.valueOf(x);
        int starting=0;
        int ending=str.length()-1;
        while(starting<=ending)
        {
            if(str.charAt(starting)!=str.charAt(ending)){
                return false;
            }
            starting+=1;
            ending-=1;
        }
       return true;
    }
}