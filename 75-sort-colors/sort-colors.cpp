class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start,mid=0;
        int end = nums.size()-1;
        while(mid<=end)
        {
            switch(nums[mid]){
                case(0):
                    swap(nums[mid],nums[start]);
                    start++;
                    mid++;
                    break;
                case(1): 
                    mid++;
                    break;
                case(2):
                    swap(nums[mid],nums[end]);
                    end--;
                    break;
            } 
        }
    }
};