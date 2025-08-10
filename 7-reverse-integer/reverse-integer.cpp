class Solution {
public:
    int reverse(int x) {
        int w=x;
        vector<int> res;
        while(w!=0)
        {
            res.push_back(w%10);
            w=w/10;
        }
        long long c=0;
        for(int i=0;i<res.size();i++)
        {
            c=c*10+res[i];
        }
        if(c>INT_MAX) return 0;
        if(c<INT_MIN) return 0;
        return (int)c;
    }
};