class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, ans = 0;
        int n = s.size();
        for (int i=1 ; i<n; i++){
            if(s[i] == s[i-1]){
                curr++;
            }
            else{
                ans += min(prev,curr);
                prev = curr;
                curr =1;

            }
        }
        ans+= min(prev,curr);
        return ans;
    }
};