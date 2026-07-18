class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n+1);
        for(int i=n-1; i>=0;i--){
            res[i] = max(nums[i], res[i+1]);
        }
        int ans = 0;
        for(int i=0; i+k<n; i++){
            ans = max(ans, nums[i] + res[i+k]);
        }
        return ans;
    }
};