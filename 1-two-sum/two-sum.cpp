class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hm;
        for(int i= 0; i<nums.size(); i++)
        {
            int other = target - nums[i];
            if(hm.count(other))
            {
                vector<int> res; 
                return {i, hm[other]};
                // res.push_back(hm[other]);
                // res.push_back(i);
                // return res;
            }
            else{
                hm[nums[i]] = i;
            }
        }
        return {};
    }
};