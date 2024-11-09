class OrderedStream {
vector<string> ans;
int maxSize = 0;
int ptr=0;
public:
    OrderedStream(int n) {
        ans.resize(n);
        maxSize = n;
    }
    
    vector<string> insert(int idKey, string value) {
        ans[idKey-1] = value;
        vector<string> curr;
        while(ptr<maxSize && ans[ptr] !="")
        {
            curr.push_back(ans[ptr]);
            ptr++;
        }
        return curr;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */