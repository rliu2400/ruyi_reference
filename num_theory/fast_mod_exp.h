// log e exponentiation.
// calculates a^e mod M.
#define ll long long

const ll M = 1e9 + 7;
ll iPow(ll a, ll e) {
    ll ans = 1;
    while (e) {
        if (e & 1)
            ans = (ans * a) % M;
        e >>= 1;
        a = (a * a) % M;
    }
    return ans;
}
