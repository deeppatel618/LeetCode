class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxHeap;
        for(int i = 0; i < heights.size() - 1; i++){
            int difference = heights[i+1] - heights[i];
            if(difference <= 0)
                continue;
            
            bricks -= difference; // remove the bricks first
            maxHeap.push(difference);

            if(bricks < 0){ // Total bricks are negative which means we are not able to process the next step.
                if(ladders == 0){ // Check if there are any ladders available
                    return i;
                }
                ladders -= 1;
                bricks += maxHeap.top();
                maxHeap.pop();
            }
        }
        return heights.size() - 1; 
    }
};