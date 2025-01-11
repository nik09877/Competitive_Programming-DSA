#define ll long long
struct seg {
    vector<ll> seg;
    vector<ll> sum;
    int siz;
    
    void init(int n, long long m) {
        siz = 1;
        while(siz <= n) siz *= 2;
        seg.resize(2 * siz, 0);
        sum.resize(2 * siz, 0);
        build(0, siz - 1, 0, m, n);
    }
    
    void build(int l, int r, int x, long long val, int n) {
        if(l == r) {
            if(l < n) {
                seg[x] = val;
                sum[x] = val;
            }
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, 2 * x + 1, val, n);
        build(mid + 1, r, 2 * x + 2, val, n);

        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        
    }
    void upd(int i, int v, int x, int lx, int rx) {
        if(lx == rx) {
            seg[x] = v;
            sum[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;

        if(i <= mid)
            upd(i, v, 2 * x + 1, lx, mid);
        else
            upd(i, v, 2 * x + 2, mid + 1, rx);

        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
    }
    int indexQuery(int k, int l, int x, int lx, int rx) {
        if(seg[x] < k or lx > l) return -1;
        if(lx == rx) return lx;
        
        int mid = (lx + rx) / 2;
        
        int res = indexQuery(k, l, 2 * x + 1, lx, mid);
        
        if(res == -1)
            res = indexQuery(k, l, 2 * x + 2, mid + 1, rx);
        
        return res;
    }
    
    ll sumQuery(int l, int r, int x, int lx, int rx) {
        if(lx > r or rx < l) return 0;
        if(lx >= l and rx <= r) return sum[x];
        
        int mid = (lx + rx) / 2;
        return sumQuery(l, r, 2 * x + 1, lx, mid) + sumQuery(l, r, 2 * x + 2, mid + 1, rx);
    }
    
    void upd(int ind, int val) {
        upd(ind, val, 0, 0, siz - 1);
    }
    
    int indexQuery(int val, int l) {
        return indexQuery(val, l, 0, 0, siz - 1);
    }
    
    ll sumQuery(int l, int r) {
        return sumQuery(l, r, 0, 0, siz - 1);
    }
};

class BookMyShow {
public:
    seg tree;
    vector<ll> cur;
    ll M;
    
    BookMyShow(int n, int m) {
        tree.init(n, m);
        cur.resize(n, m);
        M = m;
    }
    
    vector<int> gather(int k, int maxRow) {
        int row = tree.indexQuery(k, maxRow);
        if(row == -1) return vector<int> {};
        
        int col = M - cur[row];
        cur[row] -= k;
        
        tree.upd(row, cur[row]);
        return {row, col};
    }
    
    bool scatter(int k, int maxRow) {
        ll sum = tree.sumQuery(0, maxRow);
   
        if(sum < k) return 0;
        
        for(int i = 0; i <= maxRow and k; ++i) {
            if(cur[i] > 0) {
                ll mn = min(cur[i], 1LL * k);
                cur[i] -= mn;
                k -= mn;
                tree.upd(i, cur[i]);
            }
        }
        
        return 1;
    }
};