class Solution {
public:
    bool solve(int start, int subsetSum, int k, int n, vector<int> &subsetSums, vector<int> &nums) {
        if(start == n) {
            return true;
        }

        for(int i=0; i<k; i++) {
            if(subsetSums[i] + nums[start] > subsetSum)
                continue;

            if(i > 0 && subsetSums[i] == subsetSums[i-1]) {
                continue;
            }
            
            subsetSums[i] += nums[start];
            if(solve(start + 1, subsetSum, k,  n, subsetSums, nums))
                return true;
            subsetSums[i] -= nums[start];
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        for(int num: nums)
            sum += num;
        
        if(sum % k != 0)
            return false;
        
        sort(nums.begin(), nums.end(), std::greater<int>());

        int subsetSum = sum/k;
        if(nums[0] > subsetSum)
            return false;

        vector<int> subsetSums(k, 0);


        return solve(0, subsetSum, k, n, subsetSums, nums);
    }
};