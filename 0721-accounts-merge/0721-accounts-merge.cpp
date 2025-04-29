class Solution {
public:
    // First of all create one map which will have email id to index
    // Johnsmith@gmail.com ->0 , john_newyork@mail.com -> 0 .....

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        const int n = accounts.size();
        DSU ds(n);


        unordered_map<string,int> mailToNode;
        // Fetch mail from all list [name, Email]
        for(int i = 0; i < n; i++){
            for(int j = 1; j< accounts[i].size(); j++){
                string mail = accounts[i][j];
                // look if the mail is already there in the map. 
                if(mailToNode.find(mail) == mailToNode.end()){
                    mailToNode[mail] = i; 
                }else{ // if its not there. Connect the node 2 in the DSU.
                        // for our case 0 and 1 john will be connected
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }
        // At this point you will have the map and the ds with connected components.

        // Now combine the common ones.
        vector<string> mergedMail[n];
        for(auto it:mailToNode){
            string mail = it.first;
            int parentNode = ds.find(it.second);
            mergedMail[parentNode].push_back(mail);
        }
        // You will have all the combined list from now
        // 0 -> all emails
        // 1 -> empty as all the emails are combined in 0
        // ....

        // Now convert the answer from 0-> mails to name,emails

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); // insert name
            for(auto it:mergedMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        } 
        return ans;

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