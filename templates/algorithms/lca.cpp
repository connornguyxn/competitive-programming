vector<int> tin, tout;
int timer, lg;
vector2<int> up;
////////////////////////////////////////
void dfs(int cur, int pre) {
    tin[cur] = ++timer;
    
    up[0][cur] = pre;
    FOR(i, 1, lg) {
        up[i][cur] = up[i - 1][up[i - 1][cur]];
    }
    
    FORIN(nxt, adj[cur]) {
        dfs(nxt, cur);
    }
    
    tout[cur] = timer;
}
////////////////////////////////////////
bool isansc(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}
////////////////////////////////////////
int lca(int u, int v) {
    if (isansc(u, v)) return u;
    if (isansc(v, u)) return v;
    FORD(i, lg, 0) {
        if (!isansc(up[i][v], u)) v = up[i][v];
    }
    return up[0][v];
}
////////////////////////////////////////
void main() {
    lg = __lg(n) + 1;
    assign(lg + 1, vector<int>(n + 1), up);
    timer = 0;
    resize(n + 1, tin, tout);
    dfs(1, 1);
}