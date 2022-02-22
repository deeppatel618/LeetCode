class Solution {
    public int titleToNumber(String columnTitle) {
        int len=columnTitle.length();
        int ans=0;
        int val=1;
        int currValue=0;
        for(int i=0;i<len;i++)
        {
            currValue=((int)columnTitle.charAt(len-i-1))-64;
            
            ans+=val*currValue;
            val*=26;
            // System.out.println(ans);
        }
        return ans;
    }
}

//AB 27+2
//AZ 27+27