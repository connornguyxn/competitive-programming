#include "../template.cpp"

struct BinaryTrie {
    unique_ptr<BinaryTrie> adj[2];
    ll cnt = 0, sum = 0;
    ////////////////////////////////////////
    void insert(const int& val, const int& bit = 31) {
        cnt++;
        sum += val;
        if (bit < 0) return;
        
        int b = bit == 31 ? val >= 0 : bget(bit, val);
        
        if (!adj[b]) adj[b] = make_unique<BinaryTrie>();
        adj[b]->insert(val, bit - 1);
    }
    ////////////////////////////////////////
    ll sum_leq(const int& val, const int& bit = 31) {
        if (bit < 0) return sum;
        
        int b = bit == 31 ? val >= 0 : bget(bit, val);
        
        ll sum0 = (b && adj[0] ? adj[0]->sum : 0);
        return sum0 + (adj[b] ? adj[b]->sum_leq(val, bit - 1) : 0);
    }
    ////////////////////////////////////////
    ll sum_idx(const int& idx, const int& bit = 31) {
        if (bit < 0) return sum / cnt * idx;
        
        int cnt0 = (adj[0] ? adj[0]->cnt : 0);
        ll sum0 = (adj[0] ? adj[0]->sum : 0);
        
        if (cnt0 >= idx) {
            return (adj[0] ? adj[0]->sum_idx(idx, bit - 1) : 0);
        }
        return (adj[1] ? adj[1]->sum_idx(idx - cnt0, bit - 1) : 0) + sum0;
    }
    ////////////////////////////////////////
    int get(const int& idx, const int& bit = 31) {
        if (bit < 0) return sum / cnt;
        
        int cnt0 = (adj[0] ? adj[0]->cnt : 0);
        if (cnt0 >= idx) {
            return adj[0]->get(idx, bit - 1);
        }
        return adj[1]->get(idx - cnt0, bit - 1);
    }
};