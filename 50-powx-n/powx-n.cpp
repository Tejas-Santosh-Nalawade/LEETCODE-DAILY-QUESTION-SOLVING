class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long m=n;
        if(n<0){
            x=1/x;
            m=-m;
        }
        while(m){
            if(m%2==1){
                ans*=x;
            }
            x*=x;
            m /= 2;
        }
        return ans;
    }
};