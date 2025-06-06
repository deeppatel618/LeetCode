class Solution {
public:
    // 2 color graph where no 2 adjacent nodes should have same color
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        queue<int> q;

        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto neighbor : graph[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = !color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    //O(n) O(n)
};