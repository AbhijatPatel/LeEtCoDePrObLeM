class Solution {
public:
    long long power(long long x, long long n, long long mod) {
        if (n == 0)
            return 1;

        long long half = power(x, n / 2, mod);

        long long ans = (half * half) % mod;

        if (n % 2 == 1)
            ans = (ans * x) % mod;

        return ans;
    }

    int countGoodNumbers(long long n) {
        const long long MOD = 1000000007;

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans1 = power(5, even, MOD);
        long long ans2 = power(4, odd, MOD);

        return (ans1 * ans2) % MOD;
    }
};
