class Solution {
public:
    int helper(int value) {
        int steps = 0;
        long long num = value;  // Use long long to prevent overflow
        while(num != 1) {
            if(num % 2 == 0) {
                num = num/2;
            } else {
                num = 3*num + 1;
            }
            steps++;
        }
        return steps;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> powers;
        
        
        for(int i = lo; i <= hi; i++) {
            powers.push_back({i, helper(i)});
        }
        
        
        sort(powers.begin(), powers.end(), 
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 if(a.second == b.second) return a.first < b.first;
                 return a.second < b.second;
             });
        return powers[k-1].first;
    }
};