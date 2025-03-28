class Solution {
public:
    static constexpr int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int queryCount = queries.size();
        vector<int> result(queryCount);
        int rowCount = grid.size();
        int colCount = grid[0].size();

        int totalCells = rowCount * colCount;
        vector<int> thresholdForMaxPoints(totalCells + 1);

        vector<vector<int>> minValueToReach(rowCount,
                                            vector<int>(colCount, INT_MAX));

        minValueToReach[0][0] = grid[0][0];
        priority_queue<array<int, 3>, vector<array<int, 3>>,
                       greater<array<int, 3>>>
            minHeap;
        minHeap.push({grid[0][0], 0, 0});
        int visitedCells = 0;
        while (!minHeap.empty()) {
            array<int, 3> current = minHeap.top();
            minHeap.pop();

            thresholdForMaxPoints[++visitedCells] = current[0];

            for (const auto& direction : DIRECTIONS) {
                int newRow = current[1] + direction[0];
                int newCol = current[2] + direction[1];
                if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                    newCol < colCount &&
                    minValueToReach[newRow][newCol] == INT_MAX) {
                    minValueToReach[newRow][newCol] =
                        max(current[0], grid[newRow][newCol]);

                    minHeap.push(
                        {minValueToReach[newRow][newCol], newRow, newCol});
                }
            }
        }
        for (int i = 0; i < queryCount; i++) {
            int threshold = queries[i];
            int left = 0, right = totalCells;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (thresholdForMaxPoints[mid] < threshold) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            result[i] = left;
        }

        return result;
    }
};