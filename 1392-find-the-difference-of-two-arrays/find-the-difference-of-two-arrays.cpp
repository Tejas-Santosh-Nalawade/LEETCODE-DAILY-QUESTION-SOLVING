class Solution {
public:
    vector<int>getElement(vector<int>&nums1, vector<int>&nums2){
        unordered_set<int> onlynum1;

        for(int num : nums1){
            bool existNum1 = false;
            for(int x : nums2){
                if(x == num){
                    existNum1 = true;
                    break;
                }
            }
            if(!existNum1){
                onlynum1.insert(num);
            }
        }
        return vector<int>(onlynum1.begin(),onlynum1.end());
    }



    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getElement(nums1,nums2),getElement(nums2,nums1)};
    }
};