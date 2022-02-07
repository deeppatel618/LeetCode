class Solution {
    public boolean isPalindrome(int x) {
        boolean flag=true;
        String str=String.valueOf(x);
        char[] a=str.toCharArray();
        int starting=0;
        int ending=a.length-1;
        while(starting<=ending)
        {
            if(a[starting]!=a[ending]){
                flag=false;
                break;
            }
            starting+=1;
            ending-=1;
        }
       return flag;
    }
}