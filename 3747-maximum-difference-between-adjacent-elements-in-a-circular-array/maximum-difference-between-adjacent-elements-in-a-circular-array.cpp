class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        // if(nums.size()<2)
        // {
        //     return 0;
        // }
        // nums.push_back(nums[0]);
        // int value = 0;
        // for(int i=0; i < nums.size()-1; i++)
        // {
        //     int current_diff = abs(nums[i+1] - nums[i]);
        //     value = max(value,current_diff);
        // }
        // return value;
        int n = nums.size();
        int res = abs(nums[0] - nums[n-1]);
        for(int i=0; i<n-1; i++)
        {
            int value = abs(nums[i+1] - nums[i]);
            res = max(res, value);
        }
        return res;
    }
};