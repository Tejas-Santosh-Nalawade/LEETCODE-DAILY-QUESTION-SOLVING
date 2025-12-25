class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq;

        for(const auto& h: happiness){
            pq.push(h);
        }

        long long ans = 0;
        int turns = 0;

        for(int i=0; i<k; i++){
            ans += max(pq.top() - turns , 0);

            pq.pop();

            turns++;
        }
        return ans;
    }
};