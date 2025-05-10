class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        stack<string> st;
        for(int i=0; i<s.size(); i++){
            char ch=s[i];
            // not a space
            if(s[i]!= ' '){
                temp+=ch;
            }
            else{ // space 
                if(temp.size()>0){
                    st.push(temp);
                    temp="";
                }
            }   
        }
        // when there is no space after last word and temp has the last word
        if(temp.size()>0){
            st.push(temp);
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
            if(st.size()>0){
                ans+=" ";
            }
        }
        return ans;
    }
};