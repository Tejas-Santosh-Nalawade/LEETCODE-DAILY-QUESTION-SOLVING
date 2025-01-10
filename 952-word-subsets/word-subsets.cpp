class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bmax(26, 0); 
        for (const string& b : words2) {
            vector<int> bCount = count(b);
            for (int i = 0; i < 26; ++i) {
                bmax[i] = max(bmax[i], bCount[i]);
            }
        }
        
        vector<string> ans;
        for (const string& a : words1) {
            vector<int> aCount = count(a);
            bool valid = true;
            for (int i = 0; i < 26; ++i) {
                if (aCount[i] < bmax[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans.push_back(a);
            }
        }
        
        return ans;
    }
    
private:
    vector<int> count(const string& S) {
        vector<int> ans(26, 0);
        for (char c : S) {
            ans[c - 'a']++;
        }
        return ans;
    }
};