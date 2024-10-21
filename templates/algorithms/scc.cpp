int timer, scc;
vector<int> tin, low, root;
deque<int> stk;
vector<vector<int>> sadj;

void dfs(int cur) {
    stk.push_back(cur);
    low[cur] = tin[cur] = timer++;
    
    FORIN(nxt, adj[cur]) {
        if (del[nxt]) continue;
        if (tin[nxt] == -1) {
            dfs(nxt);
        }
        low[cur] = min(low[nxt], low[cur]);
    }
    
    if (low[cur] == tin[cur]) {
        scc++;
        vals.push_back({});
        int u;
        do {
            u = stk.back();
            root[u] = scc;
            stk.pop_back();
        } while (u != cur);
    }
}

void main() {
    resize(n + 1, root);
    assign(n + 1, -1, low, tin);
    
    FOR(i, 1, n) if (tin[i] == -1) dfs(i);
    
    resize(scc + 1, sadj);
    
    FOR(cur, 1, n) {
        FORIN(nxt, adj[cur]) {
            if (root[cur] != root[nxt]) {
                sadj[root[cur]].push_back(root[nxt]);
            }
        }
    }
}