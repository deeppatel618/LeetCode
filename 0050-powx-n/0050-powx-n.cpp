class Solution {
public:
    double myPow(double x, int n) {
        long power = abs(n);
        double ans = 1;
        while(power>0)
        {
            //odd logic
            if(power%2)
            {
                ans = ans*x;
                power -= 1;
            }
            else // even logic
            {
                x *= x;
                power= power/2;
            }
        }
        if( n<0 ) ans = 1/(double)ans;
        return ans;
    }
};