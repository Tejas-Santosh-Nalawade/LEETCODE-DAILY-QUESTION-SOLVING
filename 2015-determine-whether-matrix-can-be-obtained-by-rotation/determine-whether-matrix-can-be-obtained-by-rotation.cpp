class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t squareSize = matrix.size(), startRow = 0, startCol = 0;
        while (squareSize > 1) {
            for (size_t i = 0; i < squareSize - 1; ++i) {
                size_t ulr = startRow, ulc = startCol + i;
                size_t urr = startRow + i, urc = startCol + squareSize - 1;
                size_t llr = startRow + squareSize - 1 - i, llc = startCol;
                size_t lrr = startRow + squareSize - 1, lrc = startCol + squareSize - 1 - i;
                std::swap(matrix[ulr][ulc], matrix[urr][urc]);
                std::swap(matrix[ulr][ulc], matrix[llr][llc]);
                std::swap(matrix[llr][llc], matrix[lrr][lrc]);
            }
            ++startRow;
            ++startCol;
            squareSize -= 2;
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; ++i) {
            if (mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};