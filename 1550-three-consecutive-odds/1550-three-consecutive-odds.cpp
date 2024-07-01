class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int counter=0;
        for(auto i : arr)
        {
            if(i%2==0)
                counter=0;
            else
                counter+=1;
            if(counter ==3)
                return true;
        }
        return false;
    }
};