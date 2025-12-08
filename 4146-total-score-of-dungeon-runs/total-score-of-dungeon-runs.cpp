class Solution {
public:
    using ll = long long;

    ll totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        ll n = damage.size(), res = 0;
        vector<ll> pre(n + 1, 0);

        for(int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + damage[i];

        for(int i = 0; i < n; ++i) {
            ll need = pre[i + 1] + requirement[i] - hp; 
            int j = lower_bound(begin(pre), begin(pre) + i + 1, need) - begin(pre);
            res += max(0, i - j + 1);
        }

        return res; 
    }
};