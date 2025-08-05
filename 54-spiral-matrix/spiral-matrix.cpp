class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n = arr.size(), m= arr[0].size();
        vector<int> result;
        int top = 0, left = 0, right = m-1, bottom = n-1;
    // Outer loop for Path Border Creation
        while(top<=bottom && left<=right){
            
            // Left to Right Traversal

            // Row same Colum change
            for(int col = left; col<=right; col++){
                result.push_back(arr[top][col]);
            }
            top++;

            // Top to Bottom Traversal

            // Column same Row change 

            for(int row = top; row<=bottom; row++){
                result.push_back(arr[row][right]);
            }
            right--;

            // Right to Left Traversal

            // Row same Column Change
            if(top <= bottom){
                for(int col=right ; col>=left; col--){
                    result.push_back(arr[bottom][col]);
                }
                bottom--;
            }

            
            // Bottom to Top Traveral 
            
            // Column Same Row Change
            if(left<=right){
                for(int row = bottom; row>=top; row-- ){
                    result.push_back(arr[row][left]);
                }  
                left++; 
            }            
        }
        return result;
    }
};