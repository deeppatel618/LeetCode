class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0) return 0;
       sort(g.begin(),g.end()); 
       sort(s.begin(),s.end());
       int child = 0;
       int cookie = 0;
       while(cookie < s.size() && child<g.size())
       {
        // cout<<g[child]<<","<<s[cookie]<<endl;÷
         if(s[cookie] >= g[child])
         {
            child++;
         }
            cookie++;
       } 
       return child;
    }
};