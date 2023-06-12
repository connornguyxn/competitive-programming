#include <bits/stdc++.h>
#define maxn 300005

using namespace std;

int n, a[maxn];
vector<int> adj[maxn];

int id = 0, pos[maxn], name[maxn];
int f[maxn][20], depth[maxn];

struct ST {
    int gmax[4 * maxn];

    void update(int u, int val, int r = 1, int lo = 1, int hi = n) {
        if (lo == hi) {
            gmax[r] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if (u <= mid)
            update(u, val, 2 * r, lo, mid);
        else
            update(u, val, 2 * r + 1, mid + 1, hi);
        gmax[r] = max(gmax[2 * r], gmax[2 * r + 1]);
    }

    // Tim chi so i lon nhat de max trong doan [i,R]>=x
    int FLeft(int L, int R, int x, int r = 1, int lo = 1, int hi = n) {
        if (R < lo || L > hi)
            return 0;
        if (L <= lo && hi <= R && gmax[r] < x)
            return 0;
        if (lo == hi)
            return lo;
        int mid = (lo + hi) / 2;
        int ret = FLeft(L, R, x, 2 * r + 1, mid + 1, hi);
        if (ret)
            return ret;
        else
            return FLeft(L, R, x, 2 * r, lo, mid);
    }

    // Tim chi so i nho nhat de max trong doan [L,i]>=x
    int FRight(int L, int R, int x, int r = 1, int lo = 1, int hi = n) {
        if (R < lo || L > hi)
            return 0;
        if (L <= lo && hi <= R && gmax[r] < x)
            return 0;
        if (lo == hi)
            return lo;
        int mid = (lo + hi) / 2;
        int ret = FRight(L, R, x, 2 * r, lo, mid);
        if (ret)
            return ret;
        else
            return FRight(L, R, x, 2 * r + 1, mid + 1, hi);
    }
} T;

void DFS(int u) {
    pos[u] = ++id;
    name[id] = u;
    for(int v : adj[u]) {
        depth[v] = depth[u] + 1;
        f[v][0] = u;
        DFS(v);
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);
    while (depth[v] > depth[u]) {
        int k = log2(depth[v] - depth[u]);
        v = f[v][k];
    }
    if (u == v)
        return u;
    int k = log2(depth[u]) + 1;
    while (k >= 0) {
        if (f[u][k] != f[v][k]) {
            u = f[u][k];
            v = f[v][k];
        }
        --k;
    }
    u = f[u][0], v = f[v][0];
    return u;
}

#define task "STARTUP"
int main() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a[1];
    for(int i = 1; i <= n; ++i) {
        int u;
        cin >> a[i + 1] >> u;
        adj[u + 1].push_back(i + 1);
    }

    ++n;
    depth[1] = 1;
    DFS(1);

    // Init RMQ
    int limit = log2(n) + 1;
    for(int k = 1; k <= limit; ++k) {
        for(int i = 1; i <= n; ++i)
            f[i][k] = f[f[i][k - 1]][k - 1];
    }

    T.update(pos[1], a[1]);
    for(int i = 2; i <= n; ++i) {
        int u = T.FLeft(1, pos[i] - 1, a[i]);
        int v = T.FRight(pos[i] + 1, n, a[i]);

        u = name[u], v = name[v];
        if (u)
            u = LCA(u, i);
        if (v)
            v = LCA(i, v);
        cout << depth[i] - max(depth[u], depth[v]) - 1 << '\n';
        T.update(pos[i], a[i]);
    }
}
