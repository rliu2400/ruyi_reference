#include <vector>

/**
 *
 * Minimalist seg tree.
 * Point add, range sum.
 * Does not support lazy propogation.
 * Many variations of non-lazy seg tree exist, such as
 * - point update range query (this one)
 * - range update point query
 * O(N) initialization.
 * O(log N) queries.
 * Is not sparse or dynamic.
 * Top-down inclusive queries.
 * top-down > bottom-up tbh
 * E.g. bottom up is not suitable if you need to proprogate changes to the root.
 * This can be done in top-down with a O(1) "pull" after the recursive call within each call
 * With bottom-up, it would take O(log N) time complexity for each of the O(log N) nodes
 * That are visited, resulting in a O(log ^2 N) time complexity per query
 * However, bottom up can be shorter to code. That doesn't mean it's easier to read.
 *
 * What are the advantages over a sparse or dynamic or lazy seg tree?
 * It is fast to code and often gets the job done
 * IMO the speed gain from coding bottom up over this ver. is not really worth it.
 **/
template <typename T> class SegTree {
  private:
    std::vector<T> v; // v[0] is unused
    int N;

    void add(int i, int l, int r, int qi, T x) { // any associative binary operation over a monoid (set with id element)
        if (l == r) {
            v[i] += x;
            return;
        }

        int m = (l + r) / 2;
        if (qi <= m)
            add(2 * i, l, m, qi, x);
        if (qi > m)
            add(2 * i + 1, m + 1, r, qi, x);

        v[i] = v[2 * i] + v[2 * i + 1];
    }

    T query(int i, int l, int r, int ql, int qr) {
        if (l == r)
            return v[i];
        T ans = 0;
        int m = (l + r) / 2;
        if (ql <= m)
            ans += query(2 * i, l, m, ql, qr);
        if (qr > m)
            ans += query(2 * i + 1, m + 1, r, ql, qr);
        return ans;
    }

  public:
    SegTree(int N) : N(N), v(4 * N) {} // the 4 * N is for padding

    SegTree(std::vector<T> arr) : N(arr.size()), v(4 * arr.size()) {}

    void add(int i, T x) { add(1, 0, N - 1, i, x); } // indices 0...N - 1 of the underlying array

    T query(int l, int r) { query(1, 0, N - 1, l, r); }
};
