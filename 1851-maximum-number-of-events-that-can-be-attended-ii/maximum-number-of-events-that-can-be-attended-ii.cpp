
class Solution {
public:
    vector<vector<int>> dp;

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int n = events.size();
        dp.assign(k + 1, std::vector<int>(n, -1));

        return dfs(0, 0, events, k);
    }

private:
    int findNextEventIndex(int currentEventEndTime, int startIndex, const vector<vector<int>>& events) {
        int low = startIndex;
        int high = events.size() - 1;
        int nextIndex = events.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > currentEventEndTime) {
                nextIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nextIndex;
    }

    int dfs(int curIndex, int count,vector<vector<int>>& events, int k) {
        if (curIndex == events.size() || count == k) {
            return 0;
        }

        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }

        int ans = 0;

        int nextPossibleIndex = findNextEventIndex(events[curIndex][1], curIndex + 1, events);

        ans = max(dfs(curIndex + 1, count, events, k),
                       dfs(nextPossibleIndex, count + 1, events, k) + events[curIndex][2]);

        dp[count][curIndex] = ans;
        return ans;
    }
};