class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] arr= new int[1001];
        int[] finalArr = new int[Math.min(nums1.length,nums2.length)];
        int index=0;
        for (int i:
             nums1) {
            arr[i] ++;
        }
        for (int i:
             nums2) {
            if(arr[i]>=1)
            {
                finalArr[index++] =i;
            }
            arr[i]--;
        }
        return Arrays.copyOfRange(finalArr,0,index);
    }
}