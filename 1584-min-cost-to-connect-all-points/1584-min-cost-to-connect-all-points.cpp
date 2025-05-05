class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mstCost = 0;
        int edgesUsed = 0;
        
        // To keep track of nodes which are visited.
        vector<bool> inMst(n);

        // To keep track of minimum distance to a node
        vector<int> minDist(n,INT_MAX);
        minDist[0] = 0;
        // Iterate untill all the edges are discovered
        while(edgesUsed < n){
            int currMinEdge = INT_MAX;
            int currNode = -1;
            // Pick least weight node which is not in MST
            for(int node = 0; node < n; node++){
                if(!inMst[node] && currMinEdge > minDist[node]){
                    currMinEdge = minDist[node];
                    currNode = node;
                }
            }

            // Update the MST cost
            mstCost += currMinEdge;
            edgesUsed++; //Mark the node as visited
            inMst[currNode] = true;

            // Update the adjacent nodes with new weight
            for(int nextNode = 0; nextNode < n; nextNode++){
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);

                if (!inMst[nextNode] && minDist[nextNode] > weight) {
                    minDist[nextNode] = weight;
                }
            }
        }
        return mstCost;

    }
};