
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) return 0;

        long long min_cost = LLONG_MAX;

        if (n <= k) {
            for (long long i = 1; i <= m / 2; i++) {
                long long part1 = i;
                long long part2 = m - i;
                if (part1 <= k && part2 <= k) {
                    min_cost = min(min_cost, part1 * part2);
                }
            }
            return min_cost == LLONG_MAX ? -1 : min_cost;
        }

        if (m <= k) {
            for (long long i = 1; i <= n / 2; i++) {
                long long part1 = i;
                long long part2 = n - i;
                if (part1 <= k && part2 <= k) {
                    min_cost = min(min_cost, part1 * part2);
                }
            }
            return min_cost == LLONG_MAX ? -1 : min_cost;
        }
        return -1;
    }
};
