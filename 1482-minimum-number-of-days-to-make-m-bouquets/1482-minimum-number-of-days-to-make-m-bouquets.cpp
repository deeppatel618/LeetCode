class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = m * 1LL * k * 1LL;
        if(total> bloomDay.size()) return -1;
        int left = INT_MAX;
        int right = INT_MIN;
        int mid;
        for(int day:bloomDay)
        {
            left = min(day,left);
            right = max(day,right);
        }
        while(left<=right)
        {
            mid = left + (right - left)/2;
            int isValid = helper(bloomDay,m,k,mid);
            if(isValid)
            {
                right = mid-1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    int helper(vector<int>& bloomDay, int m, int k,int day)
    {
        int adjFlow = 0;
        int numOfBouquet = 0;
        for(int i = 0; i < bloomDay.size(); i++)
        {
            if(day>=bloomDay[i])
            {
                adjFlow++;
            }
            else{
                numOfBouquet += (adjFlow/k);
                adjFlow = 0;
            }
            
        }
        numOfBouquet+= (adjFlow/k);
        if(numOfBouquet >= m){
            return 1;
        }
        return 0;
    }
};