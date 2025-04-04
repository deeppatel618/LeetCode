class TimeMap {
public:
    // Binary search

    // Clarification on the problem - If there is no exact value for the given timestamp, you should return the value associated with the largest timestamp less than or equal to the given one.
    unordered_map<string, vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    // If L is the average length of key,value pair. Then inserting one pair would take L time(considering that the input is very long and rehashing is to be performed) and if we perform in total M operations than total timecomplexity will be ML
    void set(string key, string value, int timestamp) { 
        mp[key].push_back({value, timestamp});
    }
    
    // M at most elements-> BS -> LogM, To hash the string it takes L and if we perform N operations than the time complexity will be O(N L LogM).
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        vector<pair<string,int>> &searchableVector  = mp[key];
        return binarySearch(searchableVector,timestamp);

    }
    string binarySearch(vector<pair<string,int>> &searchableVector, int timestamp){
        int low = 0;
        int high = searchableVector.size() - 1;
        int result = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(searchableVector[mid].second == timestamp){
                return searchableVector[mid].first;
            }
            if(searchableVector[mid].second <  timestamp){
                result = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }        
        }
        return result == -1? "":searchableVector[result].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */