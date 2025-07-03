class NumArray {
public:
    vector<int>prefix;
    NumArray(vector<int>& nums) {
        for(int idx= 0; idx<nums.size(); idx++){
            int prev = (idx==0) ? 0 : prefix.back();
            prefix.push_back(prev + nums[idx]);
        }
    }

    int sumRange(int left, int right) {
        if(left==0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }
};