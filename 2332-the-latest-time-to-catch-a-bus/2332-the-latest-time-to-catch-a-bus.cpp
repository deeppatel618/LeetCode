class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int i = 0, j = 0, n = buses.size(), m = passengers.size(), currentCapacity;

        for (int k = 0; k < n; ++k) {
            currentCapacity = 0;

            // Board passengers who can catch this bus
            while (j < m && passengers[j] <= buses[k] && currentCapacity < capacity) {
                ++j;
                ++currentCapacity;
            }

            // Last bus logic
            if (k == n - 1) {
                --j;
                int time;

                // Case 1: seats still available → try arriving at the bus time
                if (currentCapacity < capacity) {
                    time = buses[k];
                } else {
                    // Case 2: bus is full → try before last boarded passenger
                    time = passengers[j];
                }

                // Step back if time is already taken
                while (j >= 0 && time == passengers[j]) {
                    --time;
                    --j;
                }

                return time;
            }
        }

        return -1; // Should never be reached
    }
};
