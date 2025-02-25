class Solution {
public:
   
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //The total gasDifference of whole has to be positive to complete one circular round.
        // At any point if the totalGas is less < 0 than it means that starting before or at that point will not lead us to the answer.
        int totalGas = 0;
        int ans = 0;
        int currGas = 0;
        for(int i = 0; i<gas.size();i++){
            totalGas += gas[i] - cost[i];
            currGas += gas[i] - cost[i];
            if(currGas<0){
                currGas = 0;
                ans = i+1;
            }
        }
        return totalGas>=0?ans:-1;
        //O(n)O(1);
    }
};