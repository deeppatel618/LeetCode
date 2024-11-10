class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int maptoT[256] = {0};
        int maptoS[256] = {0};
        for(int i =0;i<s.size();i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            if(maptoT[c1] == 0 && maptoS[c2] == 0)
            {
                maptoT[c1] = c2;
                maptoS[c2] = c1;
            }
            else if(!(maptoT[c1] == c2 && maptoS[c2] == c1))
            {
                cout<<c1<<" "<<c2<<" "<<i;
                return false;
            }
        }
        return true;
    }
};