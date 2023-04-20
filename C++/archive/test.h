#include <bits/stdc++.h>

struct edge {
    int u, v, time = 0;  // before `time`, par[u] = v
};

struct DSU {
    vector<int> par;
    vector<edge> change;
    
    DSU(int n) : par(n + 5, -1) {}

    int root(int x) {
        while (par[x] >= 0)
            x = par[x];
        return x;
    }

    bool join(int x, int y, int t) {
        if ((x = root(x)) == (y = root(y))) return false;
        //union by rank
        if (par[x] < par[y]) swap(x, y); 
        //now x's tree has less nodes than y's tree
        change.push_back({y, par[y], t});
        par[y] += par[x];
        change.push_back({x, par[x], t});
        par[x] = y;
        return true;
    }

    // rollback all changes at time > t.
    void rollback(int t) {
        while (!change.empty() && change.back().time > t) {
            par[change.back().u] = change.back().v;
            change.pop_back();
        };
    }
};
