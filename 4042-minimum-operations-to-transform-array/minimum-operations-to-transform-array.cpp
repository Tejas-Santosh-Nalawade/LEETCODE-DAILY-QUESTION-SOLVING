class Solution {
typedef long long ll;
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = n1 + 1;
        int mini = INT_MAX;
        for(int i = 0; i < n1; i++) {
            if(nums2[n2 - 1] >= nums2[i] and nums2[n2 - 1] <= nums1[i]) mini = 1;
            else if (nums2[n2 - 1] <= nums2[i] and nums2[n2 - 1] >= nums1[i]) mini = 1;
            else {
                mini = min(mini, min(abs(nums2[i] - nums2[n2 - 1]) + 1, abs(nums1[i] - nums2[n2 - 1]) + 1));
            }
        }
        ll ans = mini;
        for(int i = 0; i < n1; i++) {
            ans += abs(nums1[i] - nums2[i]);
        }
        return ans;
    }
};