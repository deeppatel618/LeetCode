class Solution {
    public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxCount = 0;
        for(int i = 0; i<tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
            maxCount = max(maxCount, freq[tasks[i] - 'A']);
        }

        int time =(maxCount - 1) * (n+1);
        for(int f:freq){
            if(f == maxCount){
                time++;
            }
        }
        return max((int)tasks.size(),time);
    }
};


class Solution2 {
public:

    /*1. Count task frequencies and store them in an array.
    2. Use a max heap to process the most frequent tasks first.
    3. Process tasks in cycles of (n + 1) to respect the cooling interval.
    4. Store remaining tasks and reinsert them into the heap after each cycle.
    5. Update total time based on tasks processed per cycle.
    6. Repeat until all tasks are completed and return the total time.*/
    int leastInterval(vector<char>& tasks, int n) {
        
        // Count frequency of all elements.
        vector<int> freq(26,0);
        for(int i = 0; i<tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
        }

        // Creating priority queue.
        priority_queue<int> pq;
        for(int i = 0; i<26 ;i++)
        {
            if(freq[i]>0)
                pq.push(freq[i]);
        }

        int time = 0;
        while(!pq.empty())
        {
            int cycle = n+1; // A,A,B,B & n = 2 then ans = A,B,_,A,B (A can be placed at n+1 gap again)
            int taskCounter = 0;
            vector<int> store;
            while(cycle && !pq.empty())
            {
                if(pq.top()>1) // If the freq is 1 or more, we add that to temp variable "Store", We will restore the freq in the prioqueue after the current cycle is finished.
                    store.push_back(pq.top() - 1);
                pq.pop();
                taskCounter++;
                cycle--;
            }
            // Restore the updated freq into the prioqueue.
            for(int i:store){
                pq.push(i);
            }
             
            time += (pq.empty() ? taskCounter : n + 1);

        
        }
        return time;
    }
};