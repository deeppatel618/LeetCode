/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
public int firstBadVersion(int n) {
        int left = 1;
        int right = n;
    
        while (left < right) {
            n = left/2 + right/2;
            if (isBadVersion(n)) {
                right = n;
            } else {
               
                left = n + 1;
            }
        }
        return left;
    }
}