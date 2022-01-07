class Solution {
    
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> hash = new HashSet<Integer>();
        for (int i = 0; i < nums.length; i++){
            hash.add(nums[i]);
            if (hash.size() != i+1 ) return true;
        }
        return false;
    }
    
}