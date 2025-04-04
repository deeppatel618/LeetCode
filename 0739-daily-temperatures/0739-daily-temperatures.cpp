class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Approach 1 - stack O(n) O(n)


        // stack<pair<int,int>> greaterTemp;
        vector<int> result(temperatures.size(),0);
        // for(int i = temperatures.size() - 1; i>=0; i--){
        //     while(!greaterTemp.empty() && greaterTemp.top().first <= temperatures[i]){
        //         greaterTemp.pop();
        //     }
        //     if(!greaterTemp.empty()){
        //         result[i] = greaterTemp.top().second - i;
        //     }
        //     greaterTemp.push({temperatures[i],i});
        // }
        // return result;


        // Use result array to calculate next warmer days(Save space). Skip the elements if they cannot be the answer. 
        // Lets say the array is 75,71,69,79. Assume that we have caluclated the answer for 71,69 and 79.
        // We have to find warmer day for 75. Lets assume that next day might be warmer and check that. It comes out to be a colder day 71. Now lets check answer for 71. The next warmer day for 71 is after 2 days. so there is no point of checking 69. we can directly jump to 79. Which can be our answer. Repeat until the warmer day is fetched or 0 is encountered.
        for(int i = temperatures.size() - 2; i>=0; i--){
            int days = 1 ;
            int currentTemperature = temperatures[i];
            while(currentTemperature >= temperatures[i+days] && result[i+days] != 0){
                days += result[i+days];
            }
            if(currentTemperature < temperatures[i+days]){
                result[i] = days;
            }
        }
        return result;
    }
};