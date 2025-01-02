class Solution {
public:
    int totalStudents(vector<int>& a, int pages)
    {
        int students = 1;
        long long currentSum = 0;
        for(int i = 0; i <a.size(); i++)
        {
            if(currentSum + a[i] <= pages)
            {
                currentSum+= a[i];
            }
            else{
                students++;
                currentSum = a[i];
            }
        }
        return students;
    }
    int splitArray(vector<int>& arr, int m) {
        int n = arr.size();
        if(m>n) return -1;
        long long high = 0; // total
        int low = INT_MIN;
        for(int i:arr)
        {
            low = max(low,i);
            high += i;
        }
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            int students = totalStudents(arr,mid);
            if(students <= m)
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};