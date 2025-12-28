class Solution {
public:
    bool fun(vector<int>& jobs, vector<int>& workers, int idx, int time){
        if(idx == jobs.size()){
            return true;
        }
        for(int i = 0; i < workers.size() ; i++){
            if(workers[i] + jobs[idx] <= time){
                workers[i] += jobs[idx];
                if(fun(jobs,workers,idx+1,time)){
                    return true;
                }
                workers[i] -= jobs[idx];
            }
            if(workers[i] == 0){
                break;
            }
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int l = ranges::max(jobs);
        int r = accumulate(jobs.begin(),jobs.end(),0);
        int ans = 0;
        vector<int> workers(k,0);
        while(l <= r ){
            int mid = l + (r-l)/2;
            auto temp = workers;
            if(fun(jobs,temp,0,mid)){
                ans = mid ;
                r = mid  - 1;
            }else{
                l = mid  + 1;
            }
        }
        return ans;
    }
};