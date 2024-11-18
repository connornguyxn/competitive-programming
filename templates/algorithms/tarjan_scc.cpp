#include "../template.cpp"

int n;
vector2<int> adj;

int timer, scc;
vector<int> tin, low, root;
deque<int> stk;
vector2<int> sadj;

void dfs(int cur) {
    stk.push_back(cur);
    low[cur] = tin[cur] = timer++;
    
    FORIN(nxt, adj[cur]) {
        if (root[nxt] != -1) continue;
        if (tin[nxt] == -1) {
            dfs(nxt);
        }
        low[cur] = min(low[nxt], low[cur]);
    }
    
    if (low[cur] == tin[cur]) {
        scc++;
        int u;
        do {
            u = stk.back();
            root[u] = scc;
            stk.pop_back();
        } while (u != cur);
    }
}

void prep() {
    assign(n + 1, -1, tin, low, root);
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