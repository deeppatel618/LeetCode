class Solution {
public:
    // int counter = 0;
    int countPairs(vector<int>& nums,int low,int mid,int high)
    {
        int counter =0;
        int right= mid+1;
        for(int i = low; i<=mid ; i++)
        {
            while(right<= high && nums[i] > (long long)nums[right]*2)
            {
                right++;
            }
            counter += (right - (mid+1));
        }
        return counter;
    }
    void merge(vector<int>& nums,int low, int mid,int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left] < nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i<=high;i++ )
        {
            nums[i] = temp[i-low];
        }
    }
    int mergeSort(vector<int>& nums,int low,int high)
    {
        int counter=0;
        if(low>=high) return counter;
        int mid = (low+high)/2;
        counter+=mergeSort(nums,low,mid);
        counter+=mergeSort(nums,mid+1,high);
        counter+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return counter;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0, nums.size()-1);
        // for(int i = 0; i < nums.size();i++)
        // {
        //     cout<<nums[i]<<" ";
        // }

        // return counter;
    }
};