// Euler's Totient Function
// O(sqrt(N))
int phi(int n) {
    int ans = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            ans -= ans / p; // guaranteed divisible
        }
    }
    if (n > 1)
        ans -= ans / n; // prime remaining
    return ans;
}
