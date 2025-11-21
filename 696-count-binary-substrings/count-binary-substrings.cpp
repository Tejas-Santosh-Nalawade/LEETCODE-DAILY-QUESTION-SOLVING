class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> st;
        int count = 1;
        int ans = 0;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                count++;
            } else {
                st.push_back(count); 
                count = 1;
            }
        }

        st.push_back(count); 

        for(int i = 1; i < st.size(); i++) {
            ans += min(st[i], st[i - 1]);
        }

        return ans;
    }
};
