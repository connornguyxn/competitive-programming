#include "../template.cpp"



struct BinaryTrie {
    unique_ptr<BinaryTrie> adj[2];
    int cnt = 0;
    ////////////////////////////////////////
    void clear() {
        adj[0].reset();
        adj[1].reset();
        cnt = 0;
    }
    ////////////////////////////////////////
    void insert(int val, int idx = 30) {
        cnt++;
        if (idx < 0) {
            return;
        }
        
        int b = bget(idx, val);
        if (!adj[b]) {
            adj[b] = make_unique<BinaryTrie>();
        }
        adj[b]->insert(val, idx - 1);
    }
    ////////////////////////////////////////
    int max_xor(int val, int idx = 30) {
        if (idx < 0) {
            return 0;
        }
        int b = bget(idx, val);
        assert(adj[0] || adj[1]);
        
        if (adj[b ^ 1]) {
            return adj[b ^ 1]->max_xor(val, idx - 1) | bmask(idx);
        }
        return adj[b]->max_xor(val, idx - 1);
    }
};