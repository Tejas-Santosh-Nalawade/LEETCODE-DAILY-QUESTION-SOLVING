class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double Sum = 0;
        
        // k size sliding window sum 1st Window from start
        for(int i=0;i<k;i++){
            Sum +=nums[i];
        }

        double avg=Sum/k;

        for(int i=k;i<n;i++){
            Sum+= nums[i] - nums[i-k];
            avg=max(avg,Sum/k);
        }

        return avg;



        
    }
};