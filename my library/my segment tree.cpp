#include <bits/stdc++.h>
using namespace std;
#define INVALID 0

// change combine and invalid as neccesary, default is sum operation
class SegmentTree {
   public:
    SegmentTree(int n, vector<int>& a) {
        this->n = n;
        tree.resize(4 * n);
        build(a, 0, n - 1, 0);
    }
    void update(int ind, int val) { update(0, n - 1, 0, ind, val); }
    int query(int x, int y) { return query(x, y, 0, n - 1, 0); }

   private:
    vector<int> tree;
    int n;
    int combine(int a, int b) { return a + b; }
    void build(vector<int>& a, int l, int r, int i) {
        if (l == r) {
            tree[i] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, l, mid, 2 * i + 1);
        build(a, mid + 1, r, 2 * i + 2);
        tree[i] = combine(tree[2 * i + 1], tree[2 * i + 2]);
    }
    void update(int l, int r, int i, int ind, int val) {
        if (l == r) {
            tree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (mid >= ind) {
            update(l, mid, 2 * i + 1, ind, val);
        } else {
            update(mid + 1, r, 2 * i + 2, ind, val);
        }
        tree[i] = combine(tree[2 * i + 1], tree[2 * i + 2]);
    }
    int query(int x, int y, int l, int r, int i) {
        if (x > r or y < l) {
            return INVALID;
        }
        if (l >= x and r <= y) {
            return tree[i];
        }
        int mid = (l + r) / 2;
        return combine(query(x, y, l, mid, 2 * i + 1), query(x, y, mid + 1, r, 2 * i + 2));
    }
};
