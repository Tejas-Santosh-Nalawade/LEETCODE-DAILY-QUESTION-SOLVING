class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0,j=0;

        int length = 0;
        int zeroCount = 0;

        while(j<n){
            if(nums[j] == 0){
                zeroCount++;
            }
            while(i<n && zeroCount > k){
                if(nums[i] == 0){
                    zeroCount--;
                }
                i++;
            }
            length = max(length,j-i+1);
            j++;
        }
        return length;
    }
    
};