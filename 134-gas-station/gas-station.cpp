class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        long long totalGas = accumulate(gas.begin(), gas.end(), 0);
        long long totalCost = accumulate(cost.begin(), cost.end(), 0);
        if (totalGas < totalCost) {
            return -1; 
        }
        int startingStation = 0;
        int currentGas = 0;
        for (int i = 0; i < n; ++i) {
            currentGas += gas[i] - cost[i]; 
            if (currentGas < 0) {
                startingStation = i + 1; 
                currentGas = 0;
            }
        }
        return startingStation;
    }
};