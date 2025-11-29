class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int cnt = 0;
        int end = 0;
        for (auto& it : intervals) {
            if (it[1] > end) {
                cnt++;
                end = it[1];
            }
            
        }

        return cnt;
    }
};