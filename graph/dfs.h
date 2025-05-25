#include <vector>
// returns yes if target can be reached
bool dfs(int curr, int target, std::vector<bool> &visited, std::vector<std::vector<int>> &AL) {
    if (curr == target)
        return true;
    visited[curr] = true;
    for (int v : AL[curr])
        if (!visited[v] && dfs(v, target, visited, AL))
            return true;
    return false;
}
