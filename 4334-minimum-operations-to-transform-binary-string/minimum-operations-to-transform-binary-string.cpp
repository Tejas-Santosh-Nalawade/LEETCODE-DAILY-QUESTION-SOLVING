class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int c=0;
        if(n==1){
            if(s1==s2){
                return 0;
            }
            if(s1[0] == '1'){
                return -1;
            }
            return 1;
        }
        char last = s1[0];
        for(int i=0; i<n-1; i++){
            if(last == s2[i]){
                last = s1[i+1];
                continue;
            }
            if(last == '0'){
                last = s1[i+1];
                c++;
            }
            else{
                if(s1[i+1] =='1'){
                    c++;
                }
                else{
                    c+=2;
                }
                last = '0';
            }
        }
        if(last != s2[n-1]){
            if(last =='0'){
                c++;
            }
            else{
                c+=2;
            }
        }
        return c;
    }
};