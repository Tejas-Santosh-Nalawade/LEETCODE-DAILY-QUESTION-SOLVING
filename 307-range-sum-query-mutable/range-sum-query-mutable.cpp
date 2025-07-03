class NumArray {
public:
    vector<int>prefix;
    vector<int> nums;

    NumArray(vector<int>& nums) {

        this->nums = nums;
        int sum = 0;

        for(int idx= 0; idx<nums.size(); idx++){
            sum+=nums[idx];
            prefix.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        if(left==0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }


    void update(int index, int newVal){
        int oldVal = nums[index];
        nums[index] = newVal;
        for(int i= index; i<nums.size(); i++){
            prefix[i] += (newVal - oldVal);
        }
    }
};