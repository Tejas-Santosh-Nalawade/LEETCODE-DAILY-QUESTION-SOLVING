class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (int idx = 0; idx < nums.size(); idx++) {
            pq.push({nums[idx], idx});
            if (idx >= k - 1) {
                while (pq.top().second < idx - k + 1) {
                    pq.pop();
                }
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};