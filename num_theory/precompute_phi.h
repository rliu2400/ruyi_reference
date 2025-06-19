void precompute(vector<int> &phi, int N) {
    for (int i = 1; i <= N; i++)
        phi[i] = i;
    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
