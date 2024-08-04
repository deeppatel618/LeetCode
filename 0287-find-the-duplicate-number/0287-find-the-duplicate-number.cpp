class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int fastPointer = nums[0];
      int slowPointer = nums[0];
        do{
            slowPointer = nums[slowPointer];
            fastPointer = nums[nums[fastPointer]];
        }while(fastPointer != slowPointer);
        slowPointer = nums[0];
        while(fastPointer != slowPointer){
            slowPointer = nums[slowPointer];
            fastPointer = nums[fastPointer];
        }
        // cout<<"slowPointer - "<< slowPointer;
        // cout<<"fastPointer - "<< fastPointer;
        return slowPointer;
    }
};