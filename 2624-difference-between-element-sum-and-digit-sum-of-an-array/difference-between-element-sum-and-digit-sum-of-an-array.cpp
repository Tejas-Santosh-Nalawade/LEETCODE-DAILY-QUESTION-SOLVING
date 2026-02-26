class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ele_sum = 0;
        int digit_sum = 0;

        for(int i=0; i<nums.size(); i++){
            ele_sum +=nums[i];
            int clone = nums[i];
            while(clone!=0){
                digit_sum += clone % 10;
                clone /=10;
            }
        }

        return ((ele_sum > digit_sum) ? (ele_sum - digit_sum) : (digit_sum - ele_sum));
    }
};