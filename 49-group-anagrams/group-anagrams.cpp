class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        // vector<vector<string>> res;
        // unordered_map<string, vector<string>> mp;
        // for(int i=0;i<arr.size();++i){
        //     string s = arr[i];
        //     sort(s.begin(),s.end());
        //     mp[s].push_back(arr[i]);
        // }
        // for(auto it=mp.begin();it!=mp.end();it++) res.push_back(it->second);

        // return res;

        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < arr.size(); i++) {
            string s = arr[i];
            vector<int> count(26, 0);
            for (int j = 0; j < s.size(); j++) {
                count[s[j] - 'a']++;
            }
            string key = " ";
            for (int k = 0; k < 26; k++) {
                key += "#" + to_string(count[k]);
            }
            mp[key].push_back(arr[i]);
        }
        vector<vector<string>>ans;
        for (auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};