#include <queue>
#include <utility>
#include <vector>

std::vector<int> dijkstra(int start, int N,
                               const std::vector<std::vector<std::pair<int, int>>> &AL) { // weight, node

    std::vector<int> dist(N, INT_MAX);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (dist[u] != -1)
            continue;
        dist[u] = w;
        for (auto [w, v] : AL[u]) {
            pq.emplace(dist[u] + w, v);
        }
    }

    return dist;
}
