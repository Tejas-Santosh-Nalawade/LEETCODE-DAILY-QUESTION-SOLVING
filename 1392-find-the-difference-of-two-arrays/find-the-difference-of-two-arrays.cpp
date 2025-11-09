class Solution {
public:

    vector<int> getinfirst(vector<int>&nums1, vector<int>&nums2){
        unordered_set<int>existnum2;
        unordered_set<int>result;
        // Inserted the num2 to set
        for(int num: nums2){
            existnum2.insert(num);
        }

        // check if num1 in set
        for(int x:nums1){
            // if found then return the position else return to the end of set 
            if(existnum2.find(x) == existnum2.end()){
                result.insert(x);
            }
        }
        return vector<int>(result.begin(),result.end());
    }


    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getinfirst(nums1,nums2),getinfirst(nums2,nums1)};
    }
};