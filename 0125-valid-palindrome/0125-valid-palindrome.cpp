class Solution {
public:
    bool alphaNum(char c) {
            return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int leftPointer = 0;
        int rightPointer = s.size() - 1;

        while(leftPointer < rightPointer){
            while(leftPointer<rightPointer && !alphaNum(s[leftPointer])) leftPointer++;
            while(leftPointer<rightPointer && !alphaNum(s[rightPointer])) rightPointer--;
            cout<<leftPointer<<" - "<<rightPointer<<endl;
            if(tolower(s[leftPointer]) == tolower(s[rightPointer])){
                leftPointer++;
                rightPointer--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};