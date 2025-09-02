class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N=matrix.size();
        int M=matrix[0].size();
        int start=0;
        int end=N*M-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int r=mid/M;
            int c=mid%M;
            if(matrix[r][c]==target){
                return true;
            }
            if(matrix[r][c]<target)
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
           
        }
        return false;
    }
};