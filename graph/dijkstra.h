#include <queue>
#include <utility>
#include <vector>

std::vector<int> shortest_path(int start, int N,
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
        for (std::pair<int, int> p : AL[u]) {
            pq.emplace(w + p.first, p.second);
        }
    }

    return dist;
}
