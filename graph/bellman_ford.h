#include <queue>
#include <utility>
#include <vector>

std::vector<int> bellman_ford(int start, int N,
                              const std::vector<std::vector<std::pair<int, int>>> &AL) { // weight, node

    std::vector<int> dist(N, INT_MAX);
    dist[start] = 0;

    for (int iter = 1; iter < N; ++iter) {
        bool changed = false;

        for (int u = 0; u < N; ++u) {
            if (dist[u] == INT_MAX)
                continue; // unreachable so far

            for (std::pair<int, int> p : AL[u]) {
                auto [w, v] = p;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }
        }
        if (!changed)
            break; // early exit
    }

    /*  // optional negative‑cycle check
    for (int u = 0; u < N; ++u) {
        if (dist[u] == INT_MAX) continue;
        for (std::pair<int,int> p : AL[u]) {
            int w = p.first, v = p.second;
            if (dist[u] + w < dist[v]) {
                // vertex v is reachable from a negative cycle
                // handle as required (e.g. set dist[v] = -INF or throw)
            }
        }
    }
    */

    return dist;
}
