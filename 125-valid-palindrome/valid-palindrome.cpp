class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length();
        while(i<j){
            // From Starting
            if(!isalnum(s[i])){
                i++;
            }
            // From Backwards
            else if(!isalnum(s[j])){
                j--;
            }
            else if(tolower(s[i]) == tolower(s[j])){
                    i++;
                    j--;
            }
            else{
                return false;
            }
        }
        return true;
    }

};