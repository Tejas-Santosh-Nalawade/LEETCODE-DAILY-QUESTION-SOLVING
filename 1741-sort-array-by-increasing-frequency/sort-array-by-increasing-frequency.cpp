class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto x : mp) {
            v.push_back({x.second, x.first});
        }

        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        for (int i = 0; i < v.size(); i++) {
            int freq = v[i].first;
            int val = v[i].second;
            while (freq--) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};