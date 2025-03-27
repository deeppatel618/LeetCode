class Solution {
public:
    // Instead of sorting the array we can count the characters and create a string like #countA#countB
    vector<vector<string>> groupAnagrams(vector<string>& wordlist) {
        if(wordlist.size() == 0) return {{}};

        unordered_map<string,vector<string>> mappedData;
        int count[26];
        for(string word: wordlist){
            fill(begin(count),end(count),0);
            for(char c: word){
                count[c - 'a']++;// count the frequency.
            }
            string key = "";
            for(int i = 0; i < 26; i++){
                key += "#" + to_string(count[i]);
            }
            mappedData[key].push_back(word);
        }
        vector<vector<string>> result;
        for(auto it:mappedData){
            result.push_back(it.second);
        }
        return result;
    }
};




class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& wordlist) {
      vector<vector<string>> result;
    unordered_map<string, vector<string>> mp;

    // Iterate through each word in the wordlist
    for (int i = 0; i < wordlist.size(); i++) {
        string temp = wordlist[i];  // Copy the original word
        string sortedStr = wordlist[i];  // Create a copy of the string to sort
        sort(sortedStr.begin(), sortedStr.end());  // Sort the copied string
        mp[sortedStr].push_back(temp);  // Use sorted string as key and original word as value
    }

    // Collect all anagram groups from the map
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        result.push_back(itr->second);
    }

    return result;

    //Time Complexity: O(NKlogK), where N is the length of strs, and K is the maximum length of a string in strs. The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(KlogK) time.

//Space Complexity: O(NK), the total information content stored in ans.
        

    }
};

