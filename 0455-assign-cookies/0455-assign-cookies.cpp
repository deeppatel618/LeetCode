class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0) return 0;
       sort(g.begin(),g.end()); 
       sort(s.begin(),s.end());
       int child = g.size()-1;
       int cookie = s.size()-1;
       while(child >= 0 && cookie >= 0)
       {
        // cout<<g[child]<<","<<s[cookie]<<endl;÷
         if(g[child] <= s[cookie])
         {
            cookie--;
         }
            child--;
       } 
       return s.size() - (cookie+1);
    }
};