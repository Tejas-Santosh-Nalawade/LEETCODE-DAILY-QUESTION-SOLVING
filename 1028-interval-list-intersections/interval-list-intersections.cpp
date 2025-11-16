class Solution {
public:
    vector<vector<int>> intervalIntersection(
            vector<vector<int>>& f,          
            vector<vector<int>>& s) {
        std::vector<std::vector<int>> ans;
        int i{0};
        int j{0};
        while (i < f.size() && j < s.size()) {
            if (f[i][1] < s[j][1]) {
                if (f[i][1] >= s[j][0]) {
                    ans.push_back({std::max(s[j][0], f[i][0]), f[i][1]});
                }
                ++i;
            } else {
                if (s[j][1] >= f[i][0]) {
                    ans.push_back({std::max(s[j][0], f[i][0]), s[j][1]});
                }
                ++j;
            }
        }
        return ans;
    }
};