class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for(auto edge:times){
            graph[edge[0]-1].push_back({edge[1]-1,edge[2]});
            
        }
        vector<int> distance(n,INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k-1});
        distance[k-1]= 0;
        

        while(!pq.empty()){
            int currNode = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto i:graph[currNode]){
                if(dist + i.second < distance[i.first]){
                    distance[i.first] = dist + i.second;
                    pq.push({dist + i.second,i.first});
                }
                
            }
        }
        int result = 0;
        for(auto it:distance){
            result = max(result,it);
        }
        return result == INT_MAX?-1:result;
    }
};