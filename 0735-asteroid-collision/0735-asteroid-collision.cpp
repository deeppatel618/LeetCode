class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;

       for(int i = 0; i < asteroids.size(); i++){
            int curr = asteroids[i];
            if(st.empty() || !(st.top() > 0 &&  curr < 0)){
                st.push(curr);
                // cout<<"Pushed 1 "<<curr<<endl;
                continue;
            }
            bool flag = false;
            while(!st.empty() && st.top() > 0 &&  curr < 0)
            {
                // cout<<curr<<endl;
                if(st.top() < abs(curr)){
                    st.pop();
                }
                else if(st.top() > abs(curr)){
                    curr = st.top();
                    st.pop();
                }
                else{
                    // cout<<"Before pop and continue"<<st.top()<<endl;
                    st.pop();
                    flag = true;
                    break;
                }
            }
            if(!flag){

                st.push(curr);
                // cout<<"Pushed 2 "<<curr<<endl;
            }
       }
       
       int stackSize = st.size()-1;
       vector<int> result(stackSize+1);
       while(stackSize >= 0){
        result[stackSize] = st.top();
        stackSize--;
        st.pop();
       }
       return result; 
    }
};