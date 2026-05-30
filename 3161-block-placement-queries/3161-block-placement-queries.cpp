class Solution {
private:
    struct Node {
        long long sum;
        long long pref;
        long long suff;
        long long ms;

        Node() {}

        Node(long long s, long long p, long long sf, long long m) {
            sum = s;
            pref = p;
            suff = sf;
            ms = m;
        }
    };

    Node merge(Node l, Node r) {
        return Node(
            l.sum + r.sum,
            max(l.pref, l.sum + r.pref),
            max(l.suff + r.sum, r.suff),
            max({l.ms, r.ms, l.suff + r.pref})
        );
    }

    void build(int id, int l, int r, vector<int> &a, vector<Node> &t) {
        if(l == r) {
            t[id] = Node(a[l], max(0, a[l]), max(0, a[l]), max(0, a[l]));
            return;
        }

        int m = (l + r) / 2;
        build(2 * id + 1, l, m, a, t);
        build(2 * id + 2, m + 1, r, a, t);

        t[id] = merge(t[2 * id + 1], t[2 * id + 2]);
    }

    void update(int id, int l, int r, int p, int v, vector<Node> &t) {
        if(l == r) {
            t[id] = Node(v, max(0, v), max(0, v), max(0, v));
            return;
        }

        int m = (l + r) / 2;
        if(p <= m)
            update(2 * id + 1, l, m, p, v, t);
        else
            update(2 * id + 2, m + 1, r, p, v, t);

        t[id] = merge(t[2 * id + 1], t[2 * id + 2]);
    }

    Node query(int id, int l, int r, int st, int en, vector<Node> &t) {
        if(l > en || r < st)
            return Node(0, -1e15, -1e15, -1e15);

        if(l >= st && r <= en)
            return t[id];

        int m = (l + r) / 2;
        Node L = query(2 * id + 1, l, m, st, en, t);
        Node R = query(2 * id + 2, m + 1, r, st, en, t);

        return merge(L, R);
    }

public:
    vector<bool> getResults(vector<vector<int>>& q) {
        int n = q.size();
        int md = 0;
        
        for(int i = 0; i < n; i++) {
            if(q[i][0] == 1)
                md = max(md, q[i][1]);
            else
                md = max({md, q[i][1], q[i][2]});
        }

        vector<int> a(2 * md, 0);
        for(int i = 0; i < md; i++) {
            a[2 * i] = 1;
        }

        vector<Node> t(4 * (2 * md));
        if (md > 0) {
            build(0, 0, 2 * md - 1, a, t);
        }

        vector<bool> ans;
        for(int i = 0; i < n; i++) {
            if(q[i][0] == 1)
                update(0, 0, 2 * md - 1, 2 * q[i][1] - 1, -1e8, t);
            else
                ans.push_back(q[i][2] <= query(0, 0, 2 * md - 1, 0, 2 * q[i][1] - 1, t).ms);
        }

        return ans;
    }
};