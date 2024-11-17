class Solution {
public:
    double binarysearch(vector<int> num1,vector<int> num2)
    {
        if(num1.size() > num2.size())
        {
            return binarysearch(num2,num1);
        }
        int totalLen = num1.size()+num2.size()+1;
        int mid,mid2, low = 0, high = num1.size();
        int l1,l2,r1,r2;
        while(low<=high)
        {
            mid = (low+high)/2;
            mid2 = (totalLen / 2) - mid;

            l1 = (mid == 0) ? INT_MIN : num1[mid - 1];
            r1 = (mid == num1.size()) ? INT_MAX : num1[mid];
            l2 = (mid2 == 0) ? INT_MIN : num2[mid2 - 1];
            r2 = (mid2 == num2.size()) ? INT_MAX : num2[mid2];

                
            if(l1>r2)
                high = mid - 1;
            else if(l2>r1)
                low = mid + 1;
            else
                break;
        }
        //  cout<<l1<<" "<<r1<<endl;
        // cout<<l2<<" "<<r2<<endl;
        if((totalLen-1)%2 == 0)
            return (double(max(l1,l2)) +double(min(r1,r2)) )/2;
        else
            return max(l1,l2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return binarysearch(nums1,nums2);
    }
};