class Solution {
public:
    int app1(vector<int>& nums){
        vector<int> dp(nums.size(),1);
        int lis = 1;

        for(int i=0; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    lis = max(lis,dp[i]);
                }

            }
        }
        return lis;
    } 

    int getCeil(vector<int> &list, int x){
        int ceil = list.size();
        int left = 0, right= list.size() - 1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(list[mid]>=x){
                ceil = mid;
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
            
        }
        return ceil;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for(int &ele : nums){
            if(lis.size() ==0 || ele> lis.back()){
                lis.push_back(ele);
            }
            else{
                int ceil = getCeil(lis, ele);
                lis[ceil] = ele; 
            }
        }
        return lis.size();

    //    return app1(nums);
    }
};