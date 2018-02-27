#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long
#define lson ins<<1
#define rson ins<<1|1
#define merge tree[ins]=tree[lson]+tree[rson]
#define mid (r+l)/2

using namespace std;

const int Max = 100052;

struct Tree {
    int l, r;
    LL sum, lazy;

    void updata(LL x) {
        sum += (r - l + 1) * x;
        lazy += x;
    }
} tree[Max << 2];

LL data[Max << 2];

inline void push_down(int ins) {
    LL lazyval = tree[ins].lazy;
    if (lazyval) {
        tree[lson].updata(lazyval);
        tree[rson].updata(lazyval);
        tree[ins].lazy = 0;
    }
}

inline void push_up(int ins) {
    tree[ins].sum = tree[lson].sum + tree[rson].sum;
}

inline void build(int l, int r, int ins) {
    tree[ins].l = l, tree[ins].r = r, tree[ins].sum = tree[ins].lazy = 0;
    if (r == l) {
        tree[ins].sum = data[r];
    } else if (r > l) {
        build(l, mid, lson);
        build(mid + 1, r, rson);
        push_up(ins);
    }
}

inline void updata_tree(int ql, int qr, LL x, int ins) {
    int l = tree[ins].l, r = tree[ins].r;
    if (ql <= l && r <= qr)tree[ins].updata(x);
    else {
        push_down(ins);
        if (ql <= mid)updata_tree(ql, qr, x, lson);
        if (qr > mid)updata_tree(ql, qr, x, rson);
        push_up(ins);
    }
}

inline LL query(int ql, int qr, int ins) {
    int l = tree[ins].l, r = tree[ins].r;
    if (ql <= l && r <= qr)return tree[ins].sum;
    else {
        push_down(ins);
        LL res = 0;
        if (ql <= mid)res += query(ql, qr, lson);
        if (qr > mid)res += query(ql, qr, rson);
        return res;
    }
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int a = 1; a <= n; a++) {
            scanf("%lld", &data[a]);
        }
        build(1, n, 1);
        char opera[3];
        for (int a = 1; a <= m; a++) {
            scanf("%s", opera);
            if (opera[0] == 'Q') {
                int i, j;
                scanf("%d%d", &i, &j);
                printf("%lld\n", query(i, j, 1));
            } else {
                int i, j;
                LL x;
                scanf("%d%d%lld", &i, &j, &x);
                updata_tree(i, j, x, 1);

            }
        }
    }
    return 0;
}