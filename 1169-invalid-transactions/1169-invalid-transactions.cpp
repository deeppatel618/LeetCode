class transaction{
public:
    int time;
    int amount;
    string city;
    string tran;
    bool marked;
    transaction(int t, int a, string c, string tra)
    {
        tran = tra;
        city = c;
        time = t;
        amount = a;
        marked = false;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        if(transactions.size() == 0)
            return {};
        
        unordered_map<string, vector<transaction*>> trans;

        // separating the string data.
        for(string &st:transactions)
        {
            istringstream ss(st);
            string name = "";
            getline(ss,name,',');

            string strTime = "";
            getline(ss,strTime,',');
            int time = stoi(strTime);

            string strAmt = "";
            getline(ss,strAmt,',');
            int amount = stoi(strAmt);

            string city="";
            getline(ss,city,',');

            // cout<<name<<","<<time<<","<<amount<<","<<city<<endl;
            //creating object for each transaction
            transaction *t = new transaction(time,amount,city,st);
            //combining all transactions of same person.
            trans[name].push_back(t);
        }
        vector<string> results;
        for(auto &p: trans)
        {
            //sorting all the trans of a person in ascending order
            sort(p.second.begin(), p.second.end(),[](const transaction *a,const transaction *b){return a->time<b->time;
            });

            for(int i=0 ;i<p.second.size();i++)
            {
                //checking if the transaction is valid through 1000 limit.
                if(p.second[i]->amount>1000)
                {
                    results.push_back(p.second[i]->tran);
                    p.second[i]->marked = true;
                }
                //checking if the previous trans was completed withing 60 min or not
                if(i>0 && p.second[i]->time <= p.second[i-1]->time+60)
                {
                    int r = i-1;
                    //while loop to go back and check previous transactions within a 60-minute window
                    while(r>=0 && p.second[r]->time >= p.second[i]->time - 60)
                    {
                        //checking for different city.
                        if(p.second[i]->city != p.second[r]->city)
                        {
                            if(!p.second[r]->marked) {
                                results.push_back(p.second[r]->tran);
                                p.second[r]->marked = true;
                            }
                             
                            if(!p.second[i]->marked) {
                                p.second[i]->marked = true;
                                results.push_back(p.second[i]->tran);
                            }
                        }
                        r--;
                    }
                }
            }
        }

        return results;
    }
};