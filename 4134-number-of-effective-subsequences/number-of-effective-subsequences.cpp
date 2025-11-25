#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

class Solution {
public:
    int countEffective(vector<int>& nums) {
        int n = nums.size();
        int full = 0;
        for (int v: nums) full |= v;
        if (full == 0) return 0;

        vector<int> bits;
        for (int i=0;i<31;i++) if ((full>>i)&1) bits.push_back(i);
        int B = bits.size();
        int size = 1<<B;
        vector<int> freq(size,0);
        for (int v: nums){
            int m=0;
            for (int j=0;j<B;j++) if ((v>>bits[j])&1) m |= 1<<j;
            freq[m]++;
        }

        vector<int> dp = freq;
        for (int i=0;i<B;i++)
            for (int mask=0; mask<size; ++mask)
                if (mask & (1<<i)) dp[mask] += dp[mask ^ (1<<i)];

        vector<ll> pow2(n+1,1);
        for (int i=1;i<=n;i++) pow2[i] = (pow2[i-1]*2)%MOD;

        ll ans = 0;
        int fullMask = size - 1;
        for (int s=1;s<size;s++){
            int comp = fullMask ^ s;
            int countZero = dp[comp];
            ll term = pow2[countZero];
            if (__builtin_popcount((unsigned)s) & 1) ans = (ans + term) % MOD;
            else ans = (ans - term) % MOD;
        }
        ans = (ans % MOD + MOD) % MOD;
        return (int)ans;
    }
};