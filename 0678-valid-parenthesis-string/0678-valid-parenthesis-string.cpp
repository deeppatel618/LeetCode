class Solution {
public:
    // logic 1 - Use 2 stacks to store indices of open bracket and *. If ) is encountered than decrement from ('s stack if its empty remove from *'s stack. If both are empty return false;
    // logic 2  - use 2 pointer. left and right. Check if the string is balanced from left to right and right to left.
    bool checkValidString(string s) {
        int len = s.size();
        int leftCounter = 0;
        int rightCounter = 0;
        for(int i = 0;i<len;i++){
            if(s[i] == '(' || s[i] == '*'){
                leftCounter++;
            }else{
                leftCounter--;
            }
            if(s[len - i - 1] == ')' || s[len - i - 1] == '*'){
                rightCounter++;
            }else{
                rightCounter--;
            }

            if(rightCounter<0 || leftCounter<0){
                return false;
            }
        }
        return true;
    }
};