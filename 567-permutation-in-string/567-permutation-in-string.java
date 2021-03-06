class Solution {
  public boolean checkInclusion(String s1, String s2) {
        int[] arr=new int[26];
        int[] temp=new int[26];
        int patternLength=s1.length();
        if(patternLength> s2.length()) return false;
        for (int i = 0; i < patternLength; i++) {
            arr[ s1.charAt(i) - 'a']+=1;
            temp[s2.charAt(i) - 'a']+=1;
        }
        for (int i = 0; i < s2.length()-patternLength; i++) {
            if( matches(arr, temp)){
                return true;
            }
            else{
                temp[s2.charAt(i) - 'a']-=1;
                temp[s2.charAt(i+patternLength) - 'a']+=1;
            }
        }
      if(Arrays.equals(arr,temp)){
            return true;
        }
        return false;
    }
    public boolean matches(int[] s1map, int[] s2map) {
        for (int i = 0; i < 26; i++) {
            if (s1map[i] != s2map[i])
                return false;
        }
        return true;
    }
}
