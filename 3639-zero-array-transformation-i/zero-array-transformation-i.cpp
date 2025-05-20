class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        vector<int> deltaArray(n+1,0);
        for(const auto& query: queries)
        {
            int left = query[0];
            int right = query[1];
            deltaArray[left] +=1;
            deltaArray[right+1]-=1;
        }
        vector<int> operationCount;
        int currOperation = 0;
        for (int delta: deltaArray)
        {
            currOperation +=delta;
            operationCount.push_back(currOperation);
        }
        for(int i=0; i<n; i++)
        {
            if(operationCount[i]< nums[i])
            {
                return false;
            }
        }
        return true;
    }
};