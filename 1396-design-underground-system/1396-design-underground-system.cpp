class UndergroundSystem {
public:
    unordered_map<string, pair<double,double>> journeyData;
    unordered_map<int, pair<string ,int>> checkInData;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        //Fetching checkin data
        auto checkInDataForId = checkInData[id];
        string startStationName = checkInDataForId.first;
        int startTime = checkInDataForId.second;

        //Calculate the total travel time and increase the count by 1
        string routeKey = stationKey(startStationName,stationName);
        double TotalTime = journeyData[routeKey].first + (t - startTime);
        double totalTrips = journeyData[routeKey].second + 1;

        //Update in the map
        journeyData[routeKey] = {TotalTime,totalTrips};

        //Remove from the checkInData as the user have checked out
        checkInData.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto travelDetails = journeyData[stationKey(startStation,endStation)];
        return travelDetails.first/travelDetails.second;
        
    }
    string stationKey(string startStation, string endStation)
    {
        return startStation+"->"+endStation;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */