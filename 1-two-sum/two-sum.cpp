class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hm;
        for(int i= 0; i<nums.size(); i++)
        {
            int other = target - nums[i];
            if(hm.count(other))
            {
                // vector<int> res; 
                // res.push_back(hm[other]);
                // res.push_back(i);
                // return res;
                return {i, hm[other]};
            }
            else{
                hm[nums[i]] = i; // hashmap key value add
            }
        }
        return {-1};
    }
};