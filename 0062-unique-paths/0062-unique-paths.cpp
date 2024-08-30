class Solution {
public:
    int maxM,maxN;
    long long pathTracker(int i, int j) {
        if (i == maxM - 1 && j == maxN - 1) {
            return 1; // Return 1 when reaching the end of the grid
        }
        if (i >= maxM || j >= maxN) {
            return 0; // Return 0 if out of bounds
        }
        
        // Recursively count paths from the current position to the right and down
        return pathTracker(i + 1, j) + pathTracker(i, j + 1);
    }
    int uniquePaths(int m, int n) {
        maxM = m;
        maxN = n;
        return pathTracker(0,0);
    }
};