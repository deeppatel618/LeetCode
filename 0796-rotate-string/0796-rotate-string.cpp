class Solution {
public:
vector<int> LPS(string &pattern)
{
    int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);
        int start = 0, index = 1;

        while (index < patternLength) {
            if (pattern[index] == pattern[start]) {
                start++;
                lps[index++] = start;
            }
            else if (start > 0) {
                start = lps[start - 1];
            }
            else {
                lps[index++] = 0;
            }
        }
        return lps; 
}
bool kmpSearch(string& text, string& pattern) {
        vector<int> lps = LPS(pattern);
        int textIndex = 0, patternIndex = 0;
        int textLength = text.size(), patternLength = pattern.size();
        while (textIndex < textLength) {
            if (text[textIndex] == pattern[patternIndex]) {
                textIndex++;
                patternIndex++;
                if (patternIndex == patternLength) return true;
            }
            else if (patternIndex > 0) {
                patternIndex = lps[patternIndex - 1];
            }
            else {
                textIndex++;
            }
        }
        return false;
    }
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubledString = s + s;
        return kmpSearch(doubledString, goal);
    }
};