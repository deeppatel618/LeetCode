class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        // Store dist, node
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        // We will need one vector to store the time to reach the node and one to store the number of ways to reach their. 
        vector<long long> distance(n,LLONG_MAX);
        vector<int> ways(n,0);

        pq.push({0,0});
        distance[0] = 0; // dist to reach source = 0
        ways[0] = 1; // ways to reach source = 1
        int mod = (int)(1e9+7);
        while(!pq.empty()){
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                long long edW = it.second;

                // We are reaching here for the first time
                // or
                // reaching here with less time
                if( edW + dist< distance[adjNode]){
                    distance[adjNode] = edW + dist; // Update the distance
                    ways[adjNode] = ways[node]; // update the number of ways to reach their.
                    pq.push({edW+dist, adjNode}); // push the new node
                }
                else if(edW + dist  == distance[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }

        }
        return ways[n-1] % mod;
    }
};