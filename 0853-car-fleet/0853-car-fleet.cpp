class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double> mp; // Will store the data in sorted order of key.
        for(int i = 0; i<position.size(); i++)
        {
            mp[-position[i]] = (double)(target - position[i])/(double)speed[i];
        }
        double curr=0.0;
        int ans =0;
        for(auto it:mp)
        {   
            cout<<it.second<<endl;
            if(it.second>curr)
            {
                curr = it.second;
                ans++;
            }
        }
        return ans;
        
    }
};