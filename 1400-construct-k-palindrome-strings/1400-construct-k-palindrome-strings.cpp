class Solution {
public:
    bool canConstruct(string s, int k) {
       unordered_map<char,int> mp;
       if(s.size() <k ) return false;
       int oddCounter = 0;
       for(auto c:s)
       {
            mp[c]++;
       }
       for(auto i:mp){
        if(i.second % 2 != 0) oddCounter++; 
       } 
       return oddCounter<=k;
    }
};