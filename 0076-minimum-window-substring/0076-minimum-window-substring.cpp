class Solution {
public:
    // sliding window
    //Expand right until we get a valid window.
    //Then shrink from left as much as possible while keeping the window valid.
    //Keep track of the smallest valid window.
    // keep in mind that we have to track duplicates also.
    // One map to count the frequency of characters. another to keep track of freq in the window.

    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char,int> tCount;

        for(int i = 0; i < t.size(); i++){// Create freq map;
            tCount[t[i]]++;
        }

        int left = 0, right = 0; // 2pointers
        int requiredSize = tCount.size(); // required size in terms of unique character
        int formed = 0; // Variable for keeping track of characters in the window which are in t.
        unordered_map<char, int> windowCount;

        int ans[3] = {-1,0,0}; // To keep track of the answer.

        while(right < s.length()){
            char c = s[right];
            windowCount[c]++; // increase the freq of character in the window.

            // All the occurence of current character is in the window.(Including duplicates)
            if( tCount.find(c) != tCount.end() && tCount[c] == windowCount[c]){
                formed++;
            }

            while(left <= right && formed == requiredSize){
                char leftChar = s[left];
                if(ans[0] == -1 || right - left + 1 < ans[0]){
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }

                windowCount[leftChar]--; // Try removing the left character.

                // check if the char was in our main Map i.e if it was in t or not.
                if(tCount.find(leftChar) != tCount.end() && windowCount[leftChar] < tCount[leftChar]){
                    formed--;
                }
                left++;

            }
            right++;
        }
        return ans[0] == -1? "": s.substr(ans[1], ans[0] );
    }
    // O(m + n) m = size of s and n = size of t.
    // O(m + n) - if the window size equal to string then O(m). if all the characters in t is unique then it will be O(n)
};
// To optimize the string little bit we can remove the characters whicha are not present in the t string.
// Create one vector<element> = {{'A',0},{'B',0}}; char and location.