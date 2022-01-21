class Solution {
    public int lengthOfLongestSubstring(String s) {
    char[] arr=s.toCharArray();
    int[] db=new int[128];
    int left=0,right=0,ans=0;
    while(right < arr.length)
    {
        db[arr[right]  ]++;
        while(db[arr[right] ] > 1){
            db[arr[left]]--;
            left++;
        }
        right++;
        ans=Math.max(ans,right- left);
    }
    return ans;
    }
}