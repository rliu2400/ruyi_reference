// precomputes mod inverses from 1 to N.
// Assumes M is prime. (Fermat's Little Theorem)
#define ll long long
ll M = 1e9 + 7;
int N = 2e5;
ll *inv = new ll[N] - 1; // do not do inv[0]
inv[1] = 1;
for (int i = 2; i <= N; i++)
    inv[i] = M - (M / i) * inv[M % i] % M;
