class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long sum = 0 ;
        for(int i = 0 ; i < nums1.size() ; i++){
            sum += abs(nums1[i] - nums2[i]);
        }
        int ele = nums2[nums1.size()];
        int mini = INT_MAX;
        for(int i = 0 ; i < nums1.size() ; i++){
            int low = min(nums1[i],nums2[i]);
            int high = max(nums1[i],nums2[i]);
            if(ele >= low && ele <= high) return sum + 1;
            else{
                if(ele < low){
                    mini = min(mini,low-ele);
                }else if(ele > high){
                    mini = min(mini,ele - high);
                }
            }
        }
        return sum + mini + 1;
    }
};