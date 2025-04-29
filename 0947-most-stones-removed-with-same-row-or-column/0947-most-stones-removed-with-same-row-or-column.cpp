class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        // Decide the size of the grid.
        for(auto it:stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DSU ds(maxRow + maxCol+2);
        unordered_map<int,int> stonesNeeded;
        for(auto it:stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow,nodeCol);
            stonesNeeded[nodeRow] = 1;
            stonesNeeded[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it:stonesNeeded){
            if(ds.find(it.first) == it.first){
                cnt++;
            }
        }
        return stones.size() - cnt;
    }

    class DSU{
        private:
            int N;
            vector<int> size;
            vector<int> representative;
        public:

            DSU(int n){
                this->N = n;
                for(int i = 0; i < n; i++){
                    size.push_back(1);
                    representative.push_back(i);
                }
            }
            int find(int n){
                if(representative[n] == n){
                    return n;
                }
                return representative[n] = find(representative[n]);
            }
            int unionBySize(int n1,int n2){
                n1 = find(n1);
                n2 = find(n2);
                if(n1 == n2){
                    return 0;
                }
                else{
                    if(size[n1] > size[n2]){
                        representative[n2] = n1;
                        size[n1]+=size[n2];
                    }else{
                        representative[n1] = n2; 
                        size[n2]+=size[n1];
                    }
                    
                }
                return 1;
            }
    };
};