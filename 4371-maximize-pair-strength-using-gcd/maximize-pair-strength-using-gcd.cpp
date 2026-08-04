class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long s = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i + 1 ; j < nums.size() ; j++){
                long long a = nums[i];
                long long b = nums[j];
                long long g = gcd(a , b);
                long long str = (a / g) * (b / g);
                if (str > s) s = str;
            }
        }
        return s;
    }
};