class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size()%groupSize != 0) {
            return false;
        }
        unordered_map<int,int> mp;
        for(int i = 0; i< hand.size();i++){
            mp[hand[i]]++;
        }

        priority_queue<int,vector<int>,greater<int>> keys;

        for(auto &keyValue: mp){
            keys.push(keyValue.first);
        }

        
       
        while(!keys.empty()){
            int first = keys.top();
            for(int i = first; i < first+groupSize; i++){
                if(mp[i] == 0){
                    
                    return false;
                }
                mp[i] -= 1;
                if(mp[i] == 0){ // if freq of that element is 0 than the top element in the min heap should be the same only. if not than next group will not be formed.
                    if(i != keys.top()){
                       
                        return false;
                    }
                    keys.pop();
                }
            }
        }
        return true;
    }
};