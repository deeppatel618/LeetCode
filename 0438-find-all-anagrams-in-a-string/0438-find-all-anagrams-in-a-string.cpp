class Solution {
public:
void helper(string s, string p,vector<int> &ans) {
    vector<int> arr(26, 0); // Initialize frequency array to 0

    // Fill frequency array for characters in 'p'
    for (char ch : p) {
        arr[ch - 'a']++;
    }

    int left = 0, right = 0, currWindow = 0;
    int pLen = p.size(), sLen = s.size();

    // Traverse the string 's' using a sliding window
    while (right < sLen) {
        // Expand the window by including the current character
        if (arr[s[right] - 'a'] > 0) {
            currWindow++;
        }
        arr[s[right] - 'a']--; // Update frequency array
        right++;

        // If the window size exceeds 'p', shrink it
        if (right - left > pLen) {
            if (arr[s[left] - 'a'] >= 0) {
                currWindow--;
            }
            arr[s[left] - 'a']++; // Restore frequency for the character being removed
            left++;
        }

        // If the current window matches 'p', add the starting index
        if (currWindow == pLen) {
            ans.push_back(left);
        }
    }
    // return ans;
}
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        helper(s,p,ans);
        return ans;
    }
};