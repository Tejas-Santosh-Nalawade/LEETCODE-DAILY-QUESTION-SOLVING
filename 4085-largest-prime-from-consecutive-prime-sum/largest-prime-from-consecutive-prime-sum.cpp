class Solution {
public:
    int largestPrime(int n) {
        if(n<=1) return 0;
        vector<bool> primes(n+1,true);
        primes[0]=primes[1]=0;
        for(int i=2;i*i<=n;i++){
            if(primes[i]) {
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=false;
                }
            }
        }
        int num = 0;
        int sum = 0;
        for(int i=2;i<=n;i++){
            if(primes[i]) sum+=i;
            if(sum<=n && primes[sum]) num = sum;
            if(sum>n) break;
        }
        return num;
    }
};