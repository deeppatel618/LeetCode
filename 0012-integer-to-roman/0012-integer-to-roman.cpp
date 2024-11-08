class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbols={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> values = {1,4,5,9,10,40,50,90,100,400,500,900,1000};

        int index = values.size()-1;
        string ans="";
        while(num>0)
        {
            while(num>=values[index])
            {
                ans =ans+""+ symbols[index];
                num -= values[index];
            }
            index--;
        }
        return ans;
    }
};