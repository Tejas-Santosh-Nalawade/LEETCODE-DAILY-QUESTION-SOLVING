class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> valueToIndices;
        
        // Group indices by the value
        for (int i = 0; i < nums.size(); ++i) {
            valueToIndices[nums[i]].push_back(i);
        }
        
        int count = 0;
        
        // For each group, apply two-pointer style over indices
        for (auto& [val, indices] : valueToIndices) {
            int n = indices.size();
            for (int low = 0; low < n; ++low) {
                for (int high = low + 1; high < n; ++high) {
                    if ((indices[low] * indices[high]) % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
