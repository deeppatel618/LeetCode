class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> searchableVector  = mp[key];
        return binarySearch(searchableVector,timestamp);

    }
    string binarySearch(vector<pair<string,int>> searchableVector, int timestamp){
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