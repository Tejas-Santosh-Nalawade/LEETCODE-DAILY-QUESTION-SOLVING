class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int num = prices.size();

        vector<vector<int>> hold(k + 1, vector<int>(num, 0));
        vector<vector<int>> cash(k + 1, vector<int>(num, 0));


        for (int i = 0; i < num; i++) {
            cash[0][i] = 0;
        }

 
        hold[1][0] = cash[0][0] - prices[0];
        cash[1][0] = hold[1][0] + prices[0]; // 0

        for (int j = 2; j < k + 1; j++) {

            hold[j][0] = cash[j - 1][0] - prices[0];
            cash[j][0] = hold[j - 1][0] + prices[0]; 
        }

        for (int i = 1; i < num; i++) {
            const int p = prices[i];
            for (int j = 1; j < k + 1; j++) {
                hold[j][i] = max(hold[j][i - 1], cash[j - 1][i - 1] - p);
                cash[j][i] = max(cash[j][i - 1], hold[j][i] + p);
            }
        }

        return cash[k][num - 1];
    }
};