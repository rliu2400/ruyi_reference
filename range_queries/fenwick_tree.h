#include <vector>
#define ll long long

// binary indexed tree for range sum queries.
template <typename T> class BIT {
  private:
    std::vector<T> v; // This will be one indexed.
    int N;            // size. v.size() - 1

    void add(int i, T x) {
        while (i <= N) {
            v[i] += x;
            i += i & (-i); // this is the famous trick that gives this Fenwick Tree
                           // implementation its other name: the Binary Indexed Tree.
        }
    }

    void set(int i, T x) {
        T diff = x - v[i];
        add(i, diff);
    }

    T query(int i) { // returns range sum a[1...i]
        T ans = 0;
        while (i) {
            ans += v[i];
            i -= i & (-i);
        }
        return ans;
    }

  public:
    BIT(size_t N) : v(N + 1) {}

    BIT(std::vector<T> arr) // this assumes arr is zero indexed
        : N(arr.size() + 1),
          v(arr.size() + 1, 0) {     // N log N time complexity. O(N) can be achieved but is often unnecessary
        for (int i = 1; i <= N; i++) // Since queries are log N anyways
            set(i, arr[i - 1]);
    }

    T query(int l, int r) { // zero indexed, inclusive
        return query(r + 1) - query(l);
    }

    T prefix(int r) { return query(r + 1); }
};
