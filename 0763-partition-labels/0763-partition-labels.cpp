class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Calculate last index of every character.
        vector<int> lastIndex(26,0);
        for(int i = 0; i < s.size(); i++){
            lastIndex[s[i] - 'a'] = i;
        }
        int right = 0;
        int anchor = 0;
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            right = max(right , lastIndex[s[i] - 'a']);
            if(i == right){
                ans.push_back(right-anchor+1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};