class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> greaterTemp;
        vector<int> result(temperatures.size(),0);
        for(int i = temperatures.size() - 1; i>=0; i--){
            while(!greaterTemp.empty() && greaterTemp.top().first <= temperatures[i]){
                greaterTemp.pop();
            }
            if(!greaterTemp.empty()){
                result[i] = greaterTemp.top().second - i;
            }
            greaterTemp.push({temperatures[i],i});
        }
        return result;
    }
};