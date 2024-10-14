class Solution {
public:
    int compress(vector<char>& chars) {
       int i = 0, res = 0;
       while(i<chars.size())
       {
            int len = 1;
            while((i+len)< chars.size() && chars[i] == chars[i+len]) len++;
            
            chars[res] = chars[i];
            res++;
            if(len>1)
            {
                string temp = to_string(len);
                for(char i:temp)
                {
                    chars[res]=i;
                    res++;
                }
            }
            i +=len;
       }
       return res;

    }
};