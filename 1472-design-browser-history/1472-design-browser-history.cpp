class BrowserHistory {
public:
    vector<string> visited;
    int curr;
    int rightLimit;
    BrowserHistory(string homepage) {
        visited.push_back(homepage);
        curr = 0;
        rightLimit = 0;
    }
    
    void visit(string url) {
        curr += 1;
        if(visited.size() > curr) 
        {
            visited[curr] = url;
        }
        else
        {
            visited.push_back(url);
        }
        rightLimit = curr;
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return visited[curr];
    }
    
    string forward(int steps) {
        curr = min(rightLimit,curr+steps);
        return visited[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */