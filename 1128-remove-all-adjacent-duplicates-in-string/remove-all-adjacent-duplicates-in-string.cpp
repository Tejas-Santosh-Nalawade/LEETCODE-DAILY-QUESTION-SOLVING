class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            char ch=s[i];
             // stack has elment and it is same as current character
            if(st.size()>0 && st.top() == ch){
                st.pop();
            }
            // either stack was empty or top character was not same as current character 
            else{
                st.push(ch);
            }
        }
        string ans="";
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};