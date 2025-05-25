#include <vector>

/**
 *
 * Minimalist seg tree.
 * range update, range sum.
 * lazy
 **/
template <typename T> class SegTree {
  private:
    std::vector<T> v, lazy; // v[0] is unused
    int N;

    void apply(int i, int l, int r, T val) {
        v[i] += (r - l + 1) * val;
        lazy[i] += val;
    }

    void push(int i, int l, int r) { // pushes down, propogates
        if (lazy[i] != T(0)) {       // T(0) is the identity element of our monoid
            int m = (l + r) / 2;
            apply(2 * i, l, m, lazy[i]);
            apply(2 * i + 1, m + 1, r, lazy[i]);
            lazy[i] = T(0);
        }
    }

    void update(int i, int l, int r, int ql, int qr, T x) { // any associative binary operation over a monoid
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            apply(i, l, r, x);
            return;
        }

        int m = (l + r) / 2;
        update(2 * i, l, m, ql, qr, x);
        update(2 * i + 1, m + 1, r, ql, qr, x);

        v[i] = v[2 * i] + v[2 * i + 1];
    }

    T query(int i, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return T(0);
        if (ql <= l && r <= qr)
            return v[i];
        int m = (l + r) / 2;
        return query(2 * i, l, m, ql, qr) + query(2 * i + 1, m + 1, r, ql, qr);
    }

  public:
    SegTree(int N) : N(N), v(4 * N) {} // the 4 * N is for pupdateing

    SegTree(std::vector<T> arr) : N(arr.size()), v(4 * arr.size()) {}

    void update(int i, T x) { update(1, 0, N - 1, i, i, x); } // indices 0...N - 1 of the underlying array

    void update(int l, int r, T x) { update(1, 0, N - 1, l, r, x); }

    T query(int l, int r) { query(1, 0, N - 1, l, r); }
};
