#include "../template.cpp"

int n;

struct Segtree {
    struct Node {
        
        ////////////////////////////////////////
        friend Node operator+(const Node& ln, const Node& rn) {
            // check if node not in range, return the other
            
            Node res;
            
            
            
            return res;
        }
    };
    vector<Node> st;
    Segtree() {
        st.assign(n * 4, Node());
    }
    ////////////////////////////////////////
    void update(int p, int v, int tl = 1, int tr = n, int tv = 1) {
        if (tl == tr) {
            // update single node;
            return;
        }
        int tm = (tl + tr) / 2;
        if (p <= tm) update(p, v, tl, tm, tvl);
        else update(p, v, tm + 1, tr, tvr);
        st[tv] = st[tvl] + st[tvr];
    }
    ////////////////////////////////////////
    Node get(int l, int r, int tl = 1, int tr = n, int tv = 1) {
        if (r < tl || tr < l) return Node();
        if (l <= tl && tr <= r) return st[tv];
        int tm = (tl + tr) / 2;
        return get(l, r, tl, tm, tvl) + get(l, r, tm + 1, tr, tvr);
    }
};