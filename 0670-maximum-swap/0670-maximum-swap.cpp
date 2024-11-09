class Solution {
public:
    int maximumSwap(int num) {
        string no = to_string(num);

        int max_digit = -1,max_i = -1;
        int swap_i = -1, swap_j=-1;
        for(int i = no.size()-1;i>=0;i--)
        {
            if(max_digit < no[i])
            {
                max_digit = no[i];
                max_i = i;
            }
            if(max_digit > no[i])
            {
                swap_i = i;
                swap_j = max_i;
            }
        }
        if(swap_i != -1)
            swap(no[swap_i],no[swap_j]);
        
        return stoi(no);

    }
};