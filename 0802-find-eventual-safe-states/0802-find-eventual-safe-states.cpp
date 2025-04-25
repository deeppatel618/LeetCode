class Solution {
public:
    // Any node which is part of a cycle or is connected to a cycle cannot be a safe node as it will be stuck in the infinite loop.
    // The logic is to check if there exists a cycle or not in the graph and ignore the nodes which are part of it.

    // This can be done using pathVis which will keep track of the current path and remove the node when backtracking. If a node is in the pathVis and encountered again then it is part of the cycle
    // checkNode will help to decide if that node can be a safe node or not.
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V,0),pathVis(V,0),check(V,0);
        for(int i = 0; i < V; i++){
            if(!visited[i])
                dfsCheck(i,graph,visited,pathVis,check);
        }
        vector<int> result;
        for(int i = 0; i < V; i++){
            if(check[i] == 1) result.push_back(i);
        }
        return result;
    }

    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int> &visited, vector<int> &pathVis,vector<int> &check){
        visited[node] = 1; // This node is visited;
        pathVis[node]=1; // This node is marked for the current path;

        // Explore all the adjacent nodes of the current node
        for(auto it: adj[node]){
            if(!visited[it]){// not visited before
                if(dfsCheck(it,adj,visited,pathVis,check) == true){
                    check[node] = 0;
                    return true;
                }
                
            }
            else if(pathVis[it]){ // THe node is visited but it is part of a cycle or current path which can lead to cycle.
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1; // Indicates that this node is a safe node as it is not part of cycle
        pathVis[node] = 0; // Remove from pathVis as we are backtracking from that part.
        return false;
    }
};