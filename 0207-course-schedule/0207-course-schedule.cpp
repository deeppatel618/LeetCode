class Solution {
public:

    // Uses Kahn’s Algorithm (Topological Sort using BFS) to detect cycles in the course prerequisite graph.
// Build an adjacency list and track the indegree of each course.
// Start with courses having indegree 0 (no prerequisites) and add them to a queue.
// Iteratively process courses from the queue, reducing indegrees of neighbors.
// If all courses are visited, return true; otherwise, a cycle exists (return false).

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
		// vector<int> topo;
        int visitedNodes = 0;
        // Remove the node which has in degree 0 and update other nodes 
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			visitedNodes++;
			// node is in your topo sort
			// so remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (visitedNodes == numCourses) return true;
		return false;
    }
};