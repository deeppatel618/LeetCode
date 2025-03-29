class Solution {
public:
    int getSum(int a, int b) {
        long mask = 0xFFFFFFFF;

        while(b!=0){
            int answer = (a^b)&mask; // AND with mask to limit the intermediate stage to 32 bit.
            int carry = ((a&b)&mask) << 1;
            a = answer;
            b = carry;
        }
        return a<INT_MAX?a:~(a^mask);
    }
};