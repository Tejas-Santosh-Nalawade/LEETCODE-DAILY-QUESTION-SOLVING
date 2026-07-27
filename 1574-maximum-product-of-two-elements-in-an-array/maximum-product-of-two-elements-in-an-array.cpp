class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        int ans1 = 0;
        for(int num:nums){
            if(num > ans){
                ans1 = ans;
                ans = num;
            }
            else{
                ans1 = max(ans1, num);
            }
        }
        return (ans - 1) * (ans1 - 1);
    }
};