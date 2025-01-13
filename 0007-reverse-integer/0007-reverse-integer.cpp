class Solution {
public:
    int reverse(int x) {
        int revNum = 0;
        while(x!=0)
        {
            int pop = x%10;
            x/=10;
            if(revNum>INT_MAX/10 || (revNum ==INT_MAX /10 && pop > 7)) return 0;
            if(revNum>INT_MAX/10 || (revNum ==INT_MIN /10 && pop<-8)) return 0;
            revNum = revNum*10 + pop;
        }
        return revNum;
    }
};