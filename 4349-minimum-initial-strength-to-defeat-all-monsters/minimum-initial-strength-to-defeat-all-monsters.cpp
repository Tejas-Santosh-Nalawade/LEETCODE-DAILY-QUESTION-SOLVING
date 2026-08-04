class Solution {
public:
    long long minInitialStrength(vector<int>& m, vector<vector<int>>& b) {
        
        int n=m.size();
        vector<long long>p(n+1,0);
        for(auto v:b)
        {
            p[v[0]]+=v[2];
            p[v[1]+1]-=v[2];
        }
        vector<long long >pow(n,0);
        pow[0]=p[0];
        for(int i=1;i<n;i++)
        {
        pow[i]=pow[i-1]+p[i];
        }
        bool need=true; 
        long long ans=0;
        if(m[n-1]>pow[n-1])ans=m[n-1]-pow[n-1];
        if(!ans)
        {
            need=false;
        }
        for(int i=n-2;i>=0;i--)
        {
          if(need)
          {
                ans+=m[i];
          }
          else
          {
            if(m[i]>pow[i])
            {
                ans+=m[i]-pow[i];
                need=true;
            }
          }
        }
        return ans;
    }
};  