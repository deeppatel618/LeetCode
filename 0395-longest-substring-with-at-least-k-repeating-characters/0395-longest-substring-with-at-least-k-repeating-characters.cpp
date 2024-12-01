class Solution {
public:
    int divideAndConquer(string s, int start, int end, int k)
    {
        if(end<k) return 0; // Number of characters can't be greater than k if end is less than the requirement.

        vector<int> countMap(26,0);
        //Create hashMap
        for(int i = start; i<end;i++)
        {
            countMap[s[i] - 'a']++;
        }

        for(int mid = start; mid<end;mid++)
        {
            if(countMap[s[mid] - 'a']>=k) continue; // Valid Character

            int midNext = mid+1;
            while(midNext<end && countMap[s[midNext]-'a'] <k) // Skip all consecutive invalid character
                midNext++;

            return max(divideAndConquer(s,start,mid,k) , divideAndConquer(s,midNext, end,k));
        }
        return (end - start); // whole string is valid.
    }
    int longestSubstring(string s, int k) {
        return divideAndConquer(s,0,s.size(),k);
    }
};