class Solution {
public:
    int mySqrt(int x) {
       int low = 0, high = x;
       while(low<=high)
       {
            long long mid = low + (high - low)/2;
            long long value = mid*mid;
            if(value<= x){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
       }
       return high; 
    }
};