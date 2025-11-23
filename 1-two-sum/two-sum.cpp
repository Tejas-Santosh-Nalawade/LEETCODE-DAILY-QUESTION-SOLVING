class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hm;
        for(int i= 0; i<nums.size(); i++)
        {
            int other = target - nums[i];
            if(hm.count(other))
            {

                return {i, hm[other]};
            }
            else{
                hm[nums[i]] = i;
            }
        }
        return {-1};
    }
};