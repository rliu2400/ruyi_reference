#include <queue>
#include <vector>

bool bfs(int curr, int target, std::vector<bool> &visited, std::vector<std::vector<int>> &AL) {
    std::queue<int> q;
    q.push(curr);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == target)
            return true;
        if (visited[u])
            continue;
        visited[u] = true;
        for (int v : AL[u])
            if (!visited[v])
                q.push(v);
    }

    return false;
}
