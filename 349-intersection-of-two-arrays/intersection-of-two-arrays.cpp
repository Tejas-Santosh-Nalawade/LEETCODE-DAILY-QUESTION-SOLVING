class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int p1=0,p2=0;
        set<int> intersection;


        while(p1 < n && p2 < m){
            if(nums1[p1] == nums2[p2]){
                intersection.insert(nums1[p1]);
                p1++;
                p2++;
            }else if(nums1[p1] < nums2[p2]){
                p1++;
            }
            else{
                p2++;
            }
        }
        vector<int>result(intersection.begin(),intersection.end());
        return result;
    }
};