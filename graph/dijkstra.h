#include <queue>
#include <utility>
#include <vector>

std::vector<int> shortest_path(int start, int N, std::vector<std::vector<std::pair<int, int>>> &AL) { // weight, node

    std::vector<int> dist(N, -1);

    std::priority_queue<std::pair<int, int>> pq;
    pq.emplace(0, start);
    while (pq.size()) {
        auto &p = pq.top();
        pq.pop();
        auto [w, u] = p;
        if (dist[u] != -1)
            continue;
        dist[u] = -w;
        for (std::pair<int, int> &p : AL[u]) {
            pq.emplace(w - p.first, p.second);
        }
    }

    return dist;
}
