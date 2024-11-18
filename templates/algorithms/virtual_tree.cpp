#include "../template.cpp"

#include "lca.cpp"
vector2<int> vadj;

void build(vector<int>& a) {
    sort(all(a), [&](int x, int y) {
        return tin[x] < tin[y];
    });
    
    FOR(i, 1, size(a) - 1) {
        a.push_back(lca(a[i], a[i - 1]));
    }
    sort(all(a), [&](int x, int y) {
        return tin[x] < tin[y];
    });
    a.erase(unique(all(a)), a.end());
    
    FOR(i, 1, size(a) - 1) {
        vadj[lca(a[i - 1], a[i])].push_back(a[i]);
    }
}