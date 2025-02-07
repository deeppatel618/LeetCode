class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        // Count frequency of each character.
        for(auto character:s)
        {
            count[character - 'a']++;
        }

        // Find max frequency and max character
        int maxFreq = 0, letter = 0;
        for(int i = 0; i<count.size();i++)
        {
            if(count[i] > maxFreq)
            {
                maxFreq = count[i];
                letter  = i;
            }
        }

        // If the maxFreq character has size greater than (length of s +1)/2 than return empty string
        if(maxFreq > (s.size()+1)/2) return "";

        // Now store the most freq char at even spaces so that no 2 adjacent characters are same
        int index = 0;
        string result=s;
        while(count[letter]!=0)
        {
            result[index] = char(letter+'a');
            index+=2;
            count[letter]--;
        }

        // Add the remaining elements
        for(int i = 0; i<count.size();i++)
        {
            while(count[i]!=0)
            {
                if(index>= s.size()) index = 1; // If the even spaces are over than reset the index for odd places.

                result[index] = char(i+'a');
                index+=2;
                count[i]--;
            }
        }
        return result;
     }
};