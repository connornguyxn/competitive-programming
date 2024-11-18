#include "../template.cpp"


int n;
vector2<int> adj;
void addseg(int l, int r, int val) {}
int getseg(int l, int r) {}
int combine(int ln, int rn) {}
// if path query, updateseg/getseg tin[u] + 1, tin[v] at end of update/query function


int timer;
vector<int> tin, hev, head, depth, size, par;



void dfs(int cur) {
    int mx = 0;
    size[cur] = 1;
    
    FORIN(nxt, adj[cur]) if (nxt != par[cur]) {
        par[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        
        dfs(nxt);
        
        size[cur] += size[nxt];
        if (size[nxt] > mx) {
            mx = size[nxt];
            hev[cur] = nxt;
        }
    }
}
////////////////////////////////////////
void dcmp(int cur, int chead) {
    tin[cur] = ++timer;
    head[cur] = chead;
    
    if (hev[cur]) dcmp(hev[cur], chead);
    FORIN(nxt, adj[cur]) {
        if (nxt == par[cur] || nxt == hev[cur]) continue;
        dcmp(nxt, nxt);
    }
}



void update(int u, int v, const int& val) {
    while (head[u] != head[v]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        addseg(tin[head[v]], tin[v], val);
        v = par[head[v]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    addseg(tin[u], tin[v], val);
}
////////////////////////////////////////
int get(int u, int v) {
    int res = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        res = combine(res, getseg(tin[head[v]], tin[v]));
        v = par[head[v]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    return combine(res, getseg(tin[u], tin[v]));
}