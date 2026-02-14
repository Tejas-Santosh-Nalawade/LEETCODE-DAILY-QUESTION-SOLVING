class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_row == 0)
            return min(1, poured);
        query_glass = min(query_glass, query_row - query_glass);

    
        vector<double> dp(query_glass + 2, 0.0);
        dp[0] = (double)poured;

        for (int r = 0; r < query_row; r++) {
            int end = min(r, query_glass);
            dp[end + 1] = 0.0;  
            int next_lo = 1000000000, next_hi = -1;
            bool pouring = false;

            for (int c = end; c >= 0; --c) {
                double x = dp[c];
                if (x > 1.0) { 
                    pouring = true;
                    double overflow = (x - 1.0) * 0.5;
                    dp[c] = overflow;
                    dp[c + 1] += overflow;

                    if (c < next_lo) next_lo = c;
                    if (c > next_hi) next_hi = c;
                    if (c + 1 <= query_glass && c + 1 > next_hi) next_hi = c + 1;

                } else 
                    dp[c] = 0.0;
            }

            if (!pouring)
                return 0.0;
            int rem = query_row - (r + 1);
            if (query_glass < next_lo - rem || query_glass > next_hi + rem)
                return 0.0;
        }

        return min(1.0, dp[query_glass]);
    }
};