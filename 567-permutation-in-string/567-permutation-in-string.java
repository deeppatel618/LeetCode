class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] arr=new int[26];
        int[] temp;
        int num,steps=0;
        boolean reset=false;
        for (int i = 0; i < s1.length(); i++) {
            arr[ s1.charAt(i) - 'a']+=1;
        }
        temp=arr.clone();
        for (int i = 0; i < s2.length(); i++) {
            num=s2.charAt(i)-'a';
            if( temp[num]>0)
            {
                temp[num]--;
                steps+=1;
                reset=true;
                if(steps==s1.length()) return true;
            }
            else
            {
                if(reset)
                {
                    reset=!reset;
                    i=i-steps;
                    steps=0;
                    temp=arr.clone();
                }
            }
        }
        return false;
    }
}