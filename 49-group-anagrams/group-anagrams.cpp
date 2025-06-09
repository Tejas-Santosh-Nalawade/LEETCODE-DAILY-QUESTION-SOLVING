class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<arr.size();++i){
            string s = arr[i];
            sort(s.begin(),s.end());
            mp[s].push_back(arr[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++) res.push_back(it->second);
        
        return res;
        
    }


};