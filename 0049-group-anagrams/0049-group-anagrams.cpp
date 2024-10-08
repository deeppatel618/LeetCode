class Solution {
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
    }
};

