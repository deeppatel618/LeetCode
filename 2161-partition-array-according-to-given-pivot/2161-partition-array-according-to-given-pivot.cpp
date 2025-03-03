class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // 2 pass solution

        // vector<int> result(nums.size(),0);
        // int less =0 , greater = 0, equal = 0;
        // for(int i:nums){
        //     if(i<pivot)
        //         less++;
        //     else if(i>pivot)
        //         greater++;
        // }
        
        // greater = nums.size() - greater;
        // equal = less;
        // less = 0;
        // for(int i:nums){
        //     if(i<pivot){
        //         result[less] = i;
        //         less++;
        //     }
        //     else if(i>pivot){
        //         result[greater] = i;
        //         greater++;
        //     }
        //     else{
        //         result[equal] = i;
        //         equal++;
        //     }
        // }
        // return result;

        // One pass

        vector<int> result(nums.size(),0);
        int less = 0;
        int greater = nums.size() - 1;
        for(int i=0, j =nums.size()-1; i<nums.size();i++,j--){
            if(nums[i]<pivot){
                result[less] = nums[i];
                less++;
            }
            if(nums[j]>pivot){
                result[greater] = nums[j];
                greater--;
            }
        }
        while(less<=greater){
            result[less] = pivot;
            less++;
        }
        return result;
    }
};