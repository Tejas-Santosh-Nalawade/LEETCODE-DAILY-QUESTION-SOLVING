class Solution {
public:

    int solve(vector<vector<int>>& cuboids, int prev, int idx){
        if(idx == cuboids.size()){
            return 0;
        }
        
        int skip_idx = solve(cuboids,prev,idx+1);

        int select = 0;

        if(prev ==-1 || cuboids[prev][0] <= cuboids[idx][0] && cuboids[prev][1] <= cuboids[idx][1] && cuboids[prev][2] <= cuboids[idx][2]){
            select = cuboids[idx][2] + solve(cuboids,idx,idx+1);
        }
        return max(skip_idx, select);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(int i=0; i<n; i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end());

        int ans = solve(cuboids, -1, 0);
        return ans;
    }
};