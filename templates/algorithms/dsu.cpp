#include "../template.cpp"

// dual purpose array
// negative array value = number of nodes under it
// positive array value = parrent of node

struct DSU {
    vector<int> par;
    DSU(int n) : par(n + 1, -1) {}
    ////////////////////////////////////////
    int root(int u) {
        if (par[u] < 0) return u;
        return par[u] = root(par[u]);
    }
    ////////////////////////////////////////
    bool merge(int u, int v) {
        u = root(u); v = root(v);
        if (u == v) return false;
        if (par[u] > par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
};