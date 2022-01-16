class Solution {
   int target;
    public int search(int[] nums, int target) {
        this.target=target;
        return binSearch(nums,0,nums.length-1);
    }
    public int binSearch(int[] arr,int low,int high)
    {
        if(low <=high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (target > arr[mid]) {
                return binSearch(arr,mid+1,high);
            }
            else if(target< arr[mid]){
                return binSearch(arr,low,mid-1);
            }
        }
        return -1;
    }
}