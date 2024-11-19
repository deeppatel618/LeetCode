class Solution {
    public int singleNonDuplicate(int[] nums) {
        //[1,3,3] - different side 
        //[0,1,1,3,3] - same side
        //[1,1,2,3,3,5,5] - different side
        //[1,1,3,3,4,4,8,8,9] - same side
        int length;
        int mid=0;
        int lower=0;
        int upper=nums.length-1;
        while(lower != upper)
        {
            length = upper-lower+1;
            mid = lower+ (upper-lower)/2;
            if(((length+1)/2)%2 == 0)
            {
                if(nums[mid] == nums[mid+1])     
                    upper=mid-1;
                else if(nums[mid] == nums[mid-1])
                    lower=mid+1;
                else
                    return nums[mid];
            }
            else
            {
                if(nums[mid] == nums[mid+1])
                    lower=mid+2;
                else if(nums[mid] == nums[mid-1])
                    upper=mid-2;
                 else
                    return nums[mid];
            }

        }
        return nums[lower];
    }   
}