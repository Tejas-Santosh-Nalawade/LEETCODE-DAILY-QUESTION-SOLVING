class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        if(nums.size()<2)
        {
            return 0;
        }
        nums.push_back(nums[0]);
        int value = 0;
        for(int i=0; i < nums.size()-1; i++)
        {
            int current_diff = abs(nums[i+1] - nums[i]);
            value = max(value,current_diff);
        }
        return value;
    }
};