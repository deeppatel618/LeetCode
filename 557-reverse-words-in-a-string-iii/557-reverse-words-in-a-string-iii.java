class Solution {
    public String reverseWords(String s) {
        int left=0,current=0,steps=0,length=s.length(),prev=0;
        String ans="";
        for (int i = 0; i < length; i++) {
//            System.out.println( i==length-1);
            if(s.charAt(left) == ' ' || i==length-1)
            {
                current=left;
                if(s.charAt(left) == ' ') {
                    left--;
                }
                while(left>=prev)
                {
                    ans=ans.concat(Character.toString(s.charAt(left)));
                    left--;
                }
                left=current;
                 prev=current+1;
                if(i!=length-1){
                    ans=ans.concat(" ");
                    // System.out.println("space added");
                    left++;
                }
               

            }
            else if(s.charAt(left) != ' ' ) {
                left++;
            }
        }
        return ans;
    }
}