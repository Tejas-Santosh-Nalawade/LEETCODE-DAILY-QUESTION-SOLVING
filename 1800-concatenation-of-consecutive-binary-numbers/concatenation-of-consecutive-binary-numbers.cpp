class Solution {
public:
    int concatenatedBinary(int n) {
        long long  result = 0;
        int digits = 0;
        int MOD = 1e9+7;
        for(int num = 1; num<=n; num++){
            if((num & (num - 1)) == 0){
                digits++;
            }
            result = (((result<<digits) % MOD) + num)% MOD;
        }
        return result;
    }
};