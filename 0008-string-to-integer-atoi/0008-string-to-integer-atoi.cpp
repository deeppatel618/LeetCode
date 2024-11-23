class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int result= 0;
        int index = 0;
        int n = s.size();

        while(index<n && s[index] == ' '){ // remove the leading spaces
            index++;
        }

        if(index<n && s[index] == '+'){// Check for + or -
            sign = 1;
            index++;
        }
        else if(index<n && s[index] == '-'){
            sign = -1;
            index++;
        }
        while(index<n && isdigit(s[index])){
            int curr = s[index] - '0';
            if(result > INT_MAX/10 || (result == INT_MAX / 10 && curr > INT_MAX%10))
                return sign == 1? INT_MAX:INT_MIN;
            
            result = (result*10) + curr;
            index++;
        }
        return result*sign;
    }
};