class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Sliding window approach.
        // We will increment the left pointer when the product is greater than or equal to k.
        // The above logic will work perfectly but to count the number of subarrays we need to implement right - left + 1.
        // Lets say for the array [10,5,2,6]. We start at 10. which is less than 100
        // Moving next 10.5 <= 100. In this case if 50 is less than 100 than 5 is also less than 100 which indicates that we have to add 10,5 and 5 both to the count.
        int result = 0;
        int product = 1;
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            product *= nums[right];
            while(left <= right &&product >= k){ // Untill the product is greater than equal to k and left pointer does not pass the right pointer.
                product /=nums[left];
                left++;
            }
            result+=(right - left + 1);
        }
        return result;
        // O(n) One pass
        // O(1)
    }
};