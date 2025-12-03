class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int result = 0;
        bool key = true;

        for(int i = 0; i < nums.size(); i++){
            if(key){
                result += nums[i];
                key = !key;
            }
            else{
                result -= nums[i];
                key = !key;
            }
        }
        return result;
    }
};