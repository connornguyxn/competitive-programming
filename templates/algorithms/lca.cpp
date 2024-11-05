#include "..\template.cpp"

int n;
vector2<int> adj;

int timer, lg;
vector<int> tin, tout;
vector2<int> up;
////////////////////////////////////////
void dfs(int cur, int pre) {
    tin[cur] = ++timer;
    
    up[0][cur] = pre;
    FOR(i, 1, lg) {
        up[i][cur] = up[i - 1][up[i - 1][cur]];
    }
    
    FORIN(nxt, adj[cur]) if (nxt != pre) {
        dfs(nxt, cur);
    }
    
    tout[cur] = timer;
}
////////////////////////////////////////
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}
////////////////////////////////////////
int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    FORD(i, lg, 0) {
        if (!is_ancestor(up[i][u], v)) u = up[i][u];
    }
    return up[0][u];
}
////////////////////////////////////////
void prep() {
    timer = 0;
    lg = __lg(n);
    assign(lg + 1, vector<int>(n + 1), up);
    resize(n + 1, tin, tout);
    dfs(1, 1);
}