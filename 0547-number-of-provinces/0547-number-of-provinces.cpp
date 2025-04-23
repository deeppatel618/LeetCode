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
        int combine(int n1,int n2){
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
class Solution {
public:
    // Number of possible solutions are - 3
    // BFS, DFS and DSU
    // DFS - O(N*N) and O(N) to keep track of visited nodes + recursive stack space.
    // BFS - O(N*N) and O(N) + O(N), one extra for queue.
    // DSU - better than O(N*N) and space would be O(2N)
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        DSU dsu(n);
        int numberOfComponents = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] && dsu.find(i) != dsu.find(j)) {
                    numberOfComponents--;
                    dsu.combine(i, j);
                }
            }
        }
        return numberOfComponents;
    }
};