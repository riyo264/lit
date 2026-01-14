class Solution {
public:
    double separateSquares(vector<vector<int>>& sq) {
        struct E {
            int y;
            int t;
            int xl;
            int xr;
            bool operator<(const E& o) const {
                return y < o.y;
            }
        };
        struct B {
            double y0;
            double h;
            double w;
        };
        vector<E> ev;
        for (auto &v : sq) {
            int px = v[0], py = v[1], d = v[2];
            ev.push_back({py, 1, px, px + d});
            ev.push_back({py + d, -1, px, px + d});
        }
        sort(ev.begin(), ev.end());
        vector<pair<int,int>> cur;
        vector<B> blocks;
        double full = 0.0;
        int lastY = ev[0].y;
        for (auto &e : ev) {
            if (e.y > lastY) {
                double w = span(cur);
                double h = e.y - lastY;
                if (w > 0) {
                    blocks.push_back({(double)lastY, h, w});
                    full += w * h;
                }
            }
            if (e.t == 1) {
                cur.push_back({e.xl, e.xr});
            } else {
                for (int i = 0; i < cur.size(); i++) {
                    if (cur[i].first == e.xl && cur[i].second == e.xr) {
                        cur.erase(cur.begin() + i);
                        break;
                    }
                }
            }
            lastY = e.y;
        }
        double need = full / 2.0;
        double got = 0.0;
        for (auto &b : blocks) {
            double a = b.h * b.w;
            if (got + a >= need) {
                return b.y0 + (need - got) / b.w;
            }
            got += a;
        }
        return 0.0;
    }

private:
    double span(vector<pair<int,int>> v) {
        if (v.empty()) return 0.0;
        sort(v.begin(), v.end());
        double res = 0.0;
        double r = v[0].second;
        res += v[0].second - v[0].first;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first >= r) {
                res += v[i].second - v[i].first;
                r = v[i].second;
            } else if (v[i].second > r) {
                res += v[i].second - r;
                r = v[i].second;
            }
        }
        return res;
    }
};