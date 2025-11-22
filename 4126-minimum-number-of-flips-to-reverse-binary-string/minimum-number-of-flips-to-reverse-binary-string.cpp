class Solution {
public:
    string  getBinary(int n){
        string s="";
        while(n>0){
            if(n&1){
                s+='1';
            }else{
                s+='0';
            }
            n/=2;
        }
        return s;
    }
    int minimumFlips(int n) {
        string st= getBinary(n);
        int len=st.length();
        int cnt=0;

        for(int i=0;i<len;i++){
            if(st[i] != st[len-i-1]){
                cnt++;
            }
        }
        return cnt;
    }
};