class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(),nums2.end());
    
        vector<int>ans1;

        ans1.reserve(s1.size());

        for(auto x: s1){
            if(!s2.count(x)){
                ans1.push_back(x);
            }
        }

        vector<int>ans2;

        ans2.reserve(s2.size());

        for(auto n: s2){
            if(!s1.count(n)){
                ans2.push_back(n);
            }
        }

        return {ans1,ans2};
    }
};