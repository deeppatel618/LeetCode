class Solution {
public:
    bool isPalindrome(int num) {
    // int originalNum = num;
    if(num < 0 || (num%10 == 0 && num!=0)) return false;
    int reverseNum = 0;
    while(num>reverseNum)
    {
        reverseNum = (reverseNum*10) + num%10;
        num = num/10;
    }
    return num == reverseNum || num == reverseNum / 10;
    }
};