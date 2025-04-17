class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> valToIndices;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            for (int prevIndex : valToIndices[val]) {
                if ((prevIndex * i) % k == 0) {
                    count++;
                }
            }
            valToIndices[val].push_back(i);
        }

        return count;
    }
};
