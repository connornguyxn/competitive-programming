int n, q;
vector<vector<int>> adj;
////////////////////////////////////////
struct Node {
    int cnt = 0, l = -1, r = -1;
};
vector<Node> st;
vector<int> lz;
////////////////////////////////////////
Node cmb(Node a, Node b) {
    if (b.r == -1) return a;
    if (a.l == -1) return b;
    return {a.cnt + b.cnt + (a.r == b.l && a.r != -1), a.l, b.r};
}
////////////////////
void st_push(int cv, int cl, int cr, int cm) {
    if (lz[cv] < 0) return;
    st[cv * 2].l = st[cv * 2].r = lz[cv];
    st[cv * 2 + 1].l = st[cv * 2 + 1].r = lz[cv];
    
    st[cv * 2].cnt = cm - cl;
    st[cv * 2 + 1].cnt = cr - cm - 1;
    
    lz[cv * 2] = lz[cv * 2 + 1] = lz[cv];
    lz[cv] = -1;
}
////////////////////
void st_update(int l, int r, int v, int cl = 0, int cr = n - 1, int cv = 1) {
    if (cr < l || r < cl) return;
    if (l <= cl && cr <= r) {
        st[cv] = {cr - cl, v, v};
        lz[cv] = v;
        return;
    }
    int cm = (cl + cr) / 2;
    st_push(cv, cl, cr, cm);
    st_update(l, r, v, cl, cm, cv * 2);
    st_update(l, r, v, cm + 1, cr, cv * 2 + 1);
    st[cv] = cmb(st[cv * 2], st[cv * 2 + 1]);
}
////////////////////
Node st_get(int l, int r, int cl = 0, int cr = n - 1, int cv = 1) {
    if (cr < l || r < cl) return {};
    if (l <= cl && cr <= r) return st[cv];
    int cm = (cl + cr) / 2;
    st_push(cv, cl, cr, cm);
    return cmb(st_get(l, r, cl, cm, cv * 2), st_get(l, r, cm + 1, cr, cv * 2 + 1));
}
////////////////////////////////////////
vector<int> idx, par, head, hev, depth;
int timer;
////////////////////////////////////////
int hld_dfs(int cur) {
    int mx = 0, res = 1;
    FORIN(nxt, adj[cur]) if (nxt != par[cur]) {
        par[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        int cnt = hld_dfs(nxt);
        if (mxmz(mx, cnt)) hev[cur] = nxt;
        res += cnt;
    }
    return res;
}
////////////////////
void hld_dcmp(int cur, int h) {
    head[cur] = h;
    idx[cur] = timer++;
    
    if (hev[cur]) hld_dcmp(hev[cur], h);
    FORIN(nxt, adj[cur]) if (nxt != par[cur]) {
        if (nxt == hev[cur]) continue;
        hld_dcmp(nxt, nxt);
    }
}
////////////////////////////////////////
int hld_get(int u, int v) {
    int res = 0;
    
    while (head[u] != head[v]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        res += st_get(idx[head[v]], idx[v]).cnt;
        res += st_get(idx[par[head[v]]], idx[par[head[v]]]).r == st_get(idx[head[v]], idx[head[v]]).l;
        v = par[head[v]];
    }
    
    if (depth[u] > depth[v]) swap(u, v);
    return res + st_get(idx[u], idx[v]).cnt;
}
////////////////////
void hld_update(int u, int v, int val) {
    while (head[u] != head[v]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        st_update(idx[head[v]], idx[v], val);
        v = par[head[v]];
    }
    
    if (depth[u] > depth[v]) swap(u, v);
    st_update(idx[u], idx[v], val);
}