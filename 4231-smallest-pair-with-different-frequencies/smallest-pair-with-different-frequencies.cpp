class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        // for(int num : nums){
        //     mp[num]++;
        // }
        vector<int>res;
        for(auto &p: mp){
            res.push_back(p.first);
        }
        sort(res.begin(), res.end());

        for(int i=0; i<res.size(); i++){
            for(int j=i+1; j<res.size(); j++){
                if(mp[res[i]] != mp[res[j]]){
                    return{res[i], res[j]};
                }
            }
        }

        // int smallest = nums[0];
        // int smallest_frequency = mp[smallest];

        // for(auto &p: mp){
        //     if(p.first !=smallest && p.second !=smallest_frequency){
        //         res.push_back(p.first);
        //         return res;
        //     }
        // }
        return {-1,-1};

        // int freq[n + 1] = {0};
        // for(int i=0; i<n;  i++){
        //     freq[nums[i]]++;
        // }
    }
};