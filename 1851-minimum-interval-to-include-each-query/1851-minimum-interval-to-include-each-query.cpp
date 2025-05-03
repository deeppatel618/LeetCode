class Solution {
public:
    // The logic is to sort everything so we can easily go from left to right to process the queries and we don't have to focus selecting random intervals.
    // While processing each query we want the intervals in which the particular query falls, so we can add all the intervals which have starting time before that query.
    // Now there can be a interval which starts and ends before the query so we can remove all such queries. Or there can be intervals from last iteration which ends before the current query starts.
    // To store them we can use min heap
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Step 1: Sort the intervals based on their start value
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        // Step 2: Copy and sort the queries to process them in increasing order
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        // Map to store the result for each query (query -> min interval length)
        map<int, int> res;

        // Step 3: Min-heap to store valid intervals [interval length, interval end]
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0]; // Min-heap based on interval length
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        int i = 0; // Pointer for intervals
        // Step 4: Process each query in increasing order
        for (int q : sortedQueries) {
            // Add all intervals whose start <= current query to the heap
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r}); // Store interval length and end
                i++;
            }

            // Remove intervals from heap whose end < current query (no longer valid)
            while (!minHeap.empty() && minHeap.top()[1] < q) {
                minHeap.pop();
            }

            // If the heap is not empty, the top is the smallest interval covering the query
            res[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }

        // Step 5: Build the final result array based on original query order
        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            result[j] = res[queries[j]];
        }
        return result;
    
    }
};
