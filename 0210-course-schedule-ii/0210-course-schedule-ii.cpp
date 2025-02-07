class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> adj(numCourses);

        for(auto it:prerequisites)
        {
            adj[it[0]].push_back(it[1]); // Create adjacency list.
        }

        // Logic of topological sort.
        
        vector<int> indegree(numCourses,0);// Calculate in degree of all the nodes.
		for (int i = 0; i < numCourses; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q; 
        // Add nodes with in degree 0
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
        // Remove the node which has in degree 0 and update other nodes 
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (topo.size() == numCourses)
        {
            reverse(topo.begin(),topo.end());
            return topo;
        } 
		return {};
    
    }
};