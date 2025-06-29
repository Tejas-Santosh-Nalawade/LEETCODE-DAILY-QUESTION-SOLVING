	class Solution {
public:
    bool isPalindrome(string s, int l , int r) {
        while(l<r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
 
    void partition(string s, int idx, vector<string> &par, vector<vector<string>> &ans) {
        if(idx == s.size()) {
            ans.push_back(par);
            return;
        }
 
        for(int i=idx; i<s.size(); i++) {
            if(isPalindrome(s, idx, i)) {
                par.push_back(s.substr(idx, i-idx+1));
                partition(s, i+1, par, ans);
                par.pop_back();
            }
        }
    }
 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> par;
        partition(s, 0, par, ans);
 
        return ans;
    }
};
