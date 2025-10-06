class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0, maxCurr=0; 
        for(int i=1; i<prices.size(); i++)
        {
            maxCurr= max(0, maxCurr+=prices[i]- prices[i-1]);
            maxProfit= max(maxCurr,maxProfit);
        }
        return maxProfit;
    }
};