class Solution {
public:
    int balancedStringSplit(string s) {
        int x = 0;
        int count = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == 'L') x++;
            if(s[i] == 'R') x--;
            if(x==0) count++;
        }
        return count;
    }
};