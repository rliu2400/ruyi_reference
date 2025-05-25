#include <vector>

struct DSU {
    std::vector<int> e; // elements are 0, 1, ... N - 1
                        // interestingly, if e[i] is negative, i is the leader and -e[i] is the size
    DSU(int N) : e(N, -1) {}
    int find(int x) { return e[x] < 0 ? x : find(e[x]); } // finds the leader of x
    bool join(int x, int y) {                             // false if same set already
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (e[x] > e[y])
            std::swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};
