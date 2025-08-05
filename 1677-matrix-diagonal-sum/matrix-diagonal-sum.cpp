class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int sum =0;
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
            // Primary Diagonal Sum
                if(i == j ){
                    sum+=matrix[i][j];
                }
                // Secondary Diagonal
                else if(j == n-i-1){
                    sum+=matrix[i][j];
                }
            }
        } 
        return sum;
    }
};