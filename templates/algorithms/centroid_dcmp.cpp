#include "../template.cpp"

int n;
vector2<int> adj;


vector<int> par, del, size;
////////////////////////////////////////
void calc_size(int cur, int pre) {
    size[cur] = 1;
    FORIN(nxt, adj[cur]) {
        if (nxt == pre || del[nxt]) continue;
        calc_size(nxt, cur);
        size[cur] += size[nxt];
    }
}
////////////////////////////////////////
int centroid(int cur, int pre, int s) {
    FORIN(nxt, adj[cur]) {
        if (nxt == pre || del[nxt]) continue;
        if (size[nxt] > s) return centroid(nxt, cur, s);
    }
    return cur;
}
////////////////////////////////////////
void dcmp(int cur) {
    del[cur] = 1;
    FORIN(nxt, adj[cur]) {
        if (del[nxt]) continue;
        calc_size(nxt, cur);
        int c = centroid(nxt, nxt, size[nxt] / 2);
        par[c] = cur;
        dcmp(c);
    }
}
////////////////////////////////////////
void prep() {
    resize(n + 1, par, del, size);
    calc_size(1, 1);
    dcmp(centroid(1, 1, n / 2));
}