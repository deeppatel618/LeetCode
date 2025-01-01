class Solution {
public:
    int maxScore(string s) {
       int noOfZeros=0;
       for(auto it:s)
           if(it == '0')
               noOfZeros+=1;
        cout<<noOfZeros<<endl;
        int counter=0;
        int maxAns=0;
        for(int i=0;i <s.size();i++)
        {
            if(s[i] == '0')
               counter+=1;
            cout<<"i = "<<i<<" Counter="<<counter<<" right="<< (s.size() - (i+1)) - (noOfZeros - counter)<<endl;
            if( maxAns < counter + ((s.size() - (i+1)) - (noOfZeros - counter)))
                maxAns = counter + ((s.size() - (i+1)) - (noOfZeros - counter));
        }      
        return maxAns;
    }
};