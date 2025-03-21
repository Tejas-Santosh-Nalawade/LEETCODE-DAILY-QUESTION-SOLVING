class Solution {
public:
    int myAtoi(string s)
    {
        long long ans=0;
        int neg=1;
        bool flag=false;
        for(int i=0;i<s.length();i++)
        {
            if(flag==false && (s[i]==' ' || s[i]=='0'))
            {
                if(s[i]=='0')
                {
                    flag=true;
                }
                continue;
            }
            if(flag==false && (s[i]=='+' || s[i]=='-'))
            {
                if(s[i]=='-')
                {
                    neg=-1;
                }
                flag=true;
            }
            else if(!(s[i]>='0' && s[i]<='9'))
            {
                break;
            }
            else
            {
                flag=true;
                ans*=10;
                ans+=((s[i]-'0')*neg);
                if(ans<INT_MIN)
                {
                    return INT_MIN;
                }
                else if(ans>INT_MAX)
                {
                    return INT_MAX;
                }
            }
        }
        return ans;
    }
};