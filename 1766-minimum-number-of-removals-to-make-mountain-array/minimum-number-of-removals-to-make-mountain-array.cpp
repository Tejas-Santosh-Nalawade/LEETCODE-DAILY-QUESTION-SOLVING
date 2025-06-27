class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> longestIncSubsequence(n, 1), longestDecSubsequence(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    longestIncSubsequence[i] = max(
                        longestIncSubsequence[i], longestIncSubsequence[j] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    longestDecSubsequence[i] = max(
                        longestDecSubsequence[i], longestDecSubsequence[j] + 1);
                }
            }
        }

        int maxMountainLength = 1;

        for (int i = 1; i < n - 1; ++i) {
            if (longestIncSubsequence[i] > 1 && longestDecSubsequence[i] > 1) {
                maxMountainLength =
                    max(maxMountainLength, longestIncSubsequence[i] +
                                               longestDecSubsequence[i] - 1);
            }
        }

        return n - maxMountainLength;
    }
};