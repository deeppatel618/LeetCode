class MedianFinder {
public:
    // Brute force -1 -> Insert a number into vector everytime addNum is called.
    // Sort it before finding the median then return the median. TC - O(n logn)

    // Solution - 2-> keep the vector always sorted. When a new elements is added find a place to insert it using lower_bound to keep the array sorted. To add use vec.insert;
    // Tc - o(n) -  in this method lower_bound will be calculated using binary search but the insertion can take upto n time.

    // Optimal solution - use 2 heaps. One for lower part and another for higher part.
    // The idea is to keep the list sorted and find median from top element.

    // If no of elements are odd then store more in lowerPar. Low will have n+1 ele and high will have n ele.

    // Balance both the heap everytime we add a element.
    // TC - O(Logn) and space O(n)
    priority_queue<int> lowerPart; //MaxHeap;
    priority_queue<int, vector<int>, greater<int>> higherPart; //Min Heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lowerPart.push(num); // Push into first part;

        higherPart.push(lowerPart.top()); // Remove the highest no from lower part as it can be in the higher part.
        lowerPart.pop();

        if(lowerPart.size() < higherPart.size()){
            lowerPart.push(higherPart.top());
            higherPart.pop();
        }
    }
    
    double findMedian() {
        return lowerPart.size()> higherPart.size()? lowerPart.top(): ((double)lowerPart.top() + higherPart.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */