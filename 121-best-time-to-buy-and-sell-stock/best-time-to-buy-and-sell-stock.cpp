class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //     int bestBuy[100000];
    //     bestBuy[0]=INT_MAX;
    //     for(int i=1; i<prices.size(); i++)
    //     {
    //         bestBuy[i]=min(prices[i-1],bestBuy[i-1]);
    //     }
    //     int maxProfit=0;
    //     for(int i=0; i<prices.size(); i++)
    //     {
    //         int currentProfit=prices[i] - bestBuy[i];
    //         maxProfit = max(maxProfit, currentProfit);
    //     }
    //     return maxProfit;
    // }
    int maxProfit=0, maxCurr=0; 
    for(int i=1; i<prices.size(); i++)
    {
        maxCurr= max(0, maxCurr+=prices[i]- prices[i-1]);
        maxProfit= max(maxCurr,maxProfit);
    }
    return maxProfit;
    }
};