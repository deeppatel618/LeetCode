class Solution {
public:
    // Cosnider the variables as graph nodes and weight between the nodes as the values.
    //a/b = 2 then a->b = 2 and b->a = 1/2
    // Perform this using adjancey list
    // For the queries, start looking for start and end point, that is look for a path from a to b in the problem.
    // If there exists a path return the overall weight, if not return -1.
    map<string, vector<pair<string, double>>> adj;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        vector<double> result;
        // Build the adjacency list
       
        for(int i = 0; i < equations.size(); i++){
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];

            adj[A].push_back({B,val});
            adj[B].push_back({A,1/val});
        }

        // Step 2 - Start processing each query.

        for(auto query: queries){
            string start = query[0];
            string end = query[1];
            if(adj.find(start) == adj.end() || adj.find(end) == adj.end()){
                result.push_back(-1.0);
                continue;
            }

            map<string, int> visited;
            bool found = false;
            double val = calculateIfAPathExists(start,end,visited,1.0,found);
            result.push_back(found?val:-1.0);
        }
        return result;
    }

    double calculateIfAPathExists(string start, string end,map<string, int> &visited,double val, bool& found){
        //If start and end are the same, return the val
        if(start == end){
            found = true;
            return val;
        }
        
        // Mark the node as visited.
        visited[start] = 1;

        for(auto& p:adj[start]){// Explore all the paths.
            if(visited[p.first] == 0){ // Check if the path is already visited or not.
                double ans = calculateIfAPathExists(p.first,end,visited,val*p.second,found);
                if(found) return ans;
            }
        }
        return -1.0;
    }
};