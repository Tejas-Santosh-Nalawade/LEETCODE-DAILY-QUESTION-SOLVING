class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int N = matrix.size();
        int M = matrix[0].size();
        int row = 0, column = 0;
        int direction = 1;
        vector<int> result(N * M);
        int r = 0;

        while (row < N && column < M) {
            result[r++] = matrix[row][column];
            int new_row = row + (direction == 1 ? -1 : 1);
            int new_column = column + (direction == 1 ? 1 : -1);

            if (new_row < 0 || new_row == N || new_column < 0 || new_column == M) {
                if (direction == 1) {
                    if (column == M - 1) row++;
                    else column++;
                } else {
                    if (row == N - 1) column++;
                    else row++;
                }
                direction = 1 - direction;
            } else {
                row = new_row;
                column = new_column;
            }
        }

        return result;
    }
};