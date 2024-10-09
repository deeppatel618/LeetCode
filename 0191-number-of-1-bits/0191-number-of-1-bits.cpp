class Solution {
public:
    int hammingWeight(int n) {
        int counter =0;
        while(n!=0)
        {
            counter += (n & 1);
            n = n>>1; 
        }
        return counter;
    }
};