class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> duplicate;
        for(int num:nums){
            if(duplicate[num]>=1){
                return true;
            }
            duplicate[num]++;
        }
        return false;
    }
};