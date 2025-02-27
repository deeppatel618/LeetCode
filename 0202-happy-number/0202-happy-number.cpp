class Solution {
public:
    int happyNumberCalculator(int n){
        int ans = 0;
        while(n>0){
            int remainder = n % 10;
            ans += (remainder*remainder);
            n = n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int,int> hashMap;
        hashMap[n] = 1;
        while(n !=1){
            n = happyNumberCalculator(n);
            cout<<n<<endl;
            if(hashMap[n] == 1){
                
                return false;
            }
            hashMap[n] = 1;
        }
        return true;
    }
};