class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(char c: address){
            ans += (c == '.' ) ? "[.]" : string(1,c);
        }
        return ans;
    }   
};