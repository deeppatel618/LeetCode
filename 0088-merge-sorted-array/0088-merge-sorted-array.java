class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
       int[] a = new int[m + n];
        int k = 0, i = 0, j = 0;
        if (n != 0) {
            while (k < m + n) {

                if ( i < m && j < n && nums1[i] <= nums2[j] ) {
                    a[k] = nums1[i];
                    k++;
                    i++;
                } else if (i < m && j < n && nums1[i] > nums2[j]) {
                    a[k] = nums2[j];
                    k++;
                    j++;
                } else {
                    if (i < m) {
                        a[k] = nums1[i];
                        k++;
                        i++;
                    } else {
                        a[k] = nums2[j];
                        k++;
                        j++;
                    }
                }
            }
            k = 0;
            while (k < m + n) {
                nums1[k] = a[k];
                k++;
            }

        }
    }
}