class Solution {
public:
    using int64 = long long;
    using i128 = __int128_t;

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto count = [&](long long x) {
            long long ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                i128 l = 1;
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcd((long long)l, (long long)coins[i]);
                        l = l / g * coins[i];
                        if (l > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) continue;
                if (__builtin_popcount(mask) & 1)
                    ans += x / (long long)l;
                else
                    ans -= x / (long long)l;
            }
            return ans;
        };
        long long lo = 1, hi = 1e18;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
