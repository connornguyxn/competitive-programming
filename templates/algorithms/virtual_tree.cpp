void build(vector<int>& a) {
    sort(all(a), [&](int x, int y) {
        return tin[x] < tin[y];
    });
    FOR(i, 1, a.size() - 1) {
        a.push_back(lca(a[i], a[i - 1]));
    }
    sort(all(a), [&](int x, int y) {
        return tin[x] < tin[y];
    });
    a.erase(unique(all(a)), a.end());
    
    FORIN(it, a) {
        dp[it] = -1;
        vadj[it].clear();
    }
    FOR(i, 1, a.size() - 1) {
        vadj[lca(a[i - 1], a[i])].push_back(a[i]);
    }
}