class Solution {
public:
    // Approach 1 group by characters.
    // 1100 have 2 substrings
    // 11100 also have 2 substrings.
    // 0001111 -> min(3,4). We will have 3 types of susbtring here.
    // If we calculate the consequtive characters count then we can easily fount the answer.
    // 00110011 -> count =[2,2,2,2] -> min(2,2) + min(2,2) +min(2,2) = 6
    // Approach 1 will take O(N) time and O(N) space.
    int countBinarySubstrings2(string s) {
       int counter = 1;
       vector<int> characterCounts;
       for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                counter++;
            }
            else{
                characterCounts.push_back(counter);
                counter =1;
            }
       } 
       characterCounts.push_back(counter);
       int result = 0;
       for(int i = 1; i<characterCounts.size();i++){
            result += min(characterCounts[i-1], characterCounts[i]);
       }
       return result;
    }
    // Approach 2 - Do not use array to perform the same task. Use 2 variable current and prev.
    int countBinarySubstrings(string s) {
       int counter = 1;
       int prev = 0;
       int result = 0;
       for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                counter++;
            }
            else{
                
                if(prev !=-1){
                    result += min(prev, counter);
                    
                }
                prev = counter;
                counter =1;
            }
       } 
        result += min(prev, counter);
       
       return result;
    }
};