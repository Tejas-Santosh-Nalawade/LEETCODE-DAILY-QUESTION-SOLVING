class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int>s1(nums1.begin(),nums1.end()), s2(nums2.begin(),nums2.end());

        vector<int>temp;
        vector<vector<int>>ans;

        for(auto x:s1){
            if(!s2.count(x)){
                temp.push_back(x);
            }
        }
        ans.push_back(temp);
        temp.clear();

        for(auto n:s2){
            if(!s1.count(n)){
                temp.push_back(n);
            }
        }
        ans.push_back(temp);

        return ans;
    }
};